#include <time.h>
#include <cstdarg>
#include <stdlib.h>
#include <vector>

namespace jep
{
	void init()
	{
		srand(time(NULL));
	}

	bool booRoll(double chance)
	{
		if (chance >= 1)
			return true;

		if (chance == 0)
			return false;

		return (rand() % 1000 < chance * 1000);
	}

	int intRoll(int n1, int n2)
	{
		if (n1==n2)
			return n1;

		if (n1<n2)
			return n1 + (rand() % (1+n2-n1));

		if (n2<n1)
			return n2 + (rand() % (1+n1-n2));
	}

	int catRoll(int n, ...)
	{
		std::vector<int> ranges;

		int seedRange=0;

		va_list ratios;
		va_start (ratios, n);

		for (std::vector<int>::iterator i = ranges.begin(); i != ranges.end(); i++)
		{
			seedRange += va_arg(ratios, int);
			ranges.push_back(seedRange);
		}

		va_end (ratios);

		int seed = intRoll(1, seedRange);
		
		for (int i=0; i<n; i++)
		{
			if (seed <= ranges.at(i))
				return (i+1);
		}	
	}
}
