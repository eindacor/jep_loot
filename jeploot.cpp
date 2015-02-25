#include <time.h>
#include <cstdarg>
#include <stdlib.h>
#include <vector>
#include <map>

namespace jep
{
	void init()
	{
		srand(time(NULL));
	}

	//has a d% chance to return true
	bool booRoll(double d)
	{
		if (d >= 1)
			return true;

		if (d <= 0)
			return false;

		return (rand() % 1000 < d * 1000);
	}

	//returns a random int i such that min <= i <= max
	int intRoll(int min, int max)
	{
		if (min == max)
			return min;

		if (min<max)
			return min + (rand() % (1 + max - min));

		if (max<min)
			return max + (rand() % (1 + min - max));
	}

	//returns a random float f such that min <= f <= max, with the specified precision
	const float floatRoll(float min, float max, int precision)
	{
		float lower = (min<max ? min : max);
		float upper = (min<max ? max : min);

		float zero_offset = lower;
		lower -= zero_offset;
		upper -= zero_offset;

		double precision_multiplier = pow(10, precision);
		unsigned int max_int = int(upper * precision_multiplier);

		int random_number = rand() % (max_int + 1);
		float random_float = float(random_number) / precision_multiplier;
		random_float += zero_offset;
		return random_float;
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

	int catRoll(std::vector<int> proportions)
	{
		std::vector<int> ranges;
		int seedRange = 0;

		for (std::vector<int>::iterator i = proportions.begin(); i != proportions.end(); i++)
		{
			seedRange += *i;
			ranges.push_back(seedRange);
		}

		int seed = intRoll(1, seedRange);

		for (int i = 0; i<ranges.size(); i++)
		{
			if (seed <= ranges.at(i))
				return (i + 1);
		}
	}

	int catRoll(std::vector<int> proportions)
	{
		std::vector<int> ranges;
		int seedRange = 0;

		for (std::vector<int>::iterator i = proportions.begin(); i != proportions.end(); i++)
		{
			seedRange += *i;
			ranges.push_back(seedRange);
		}

		int seed = intRoll(1, seedRange);

		for (int i = 0; i<ranges.size(); i++)
		{
			if (seed <= ranges.at(i))
				return (i + 1);
		}
	}

}
