//#include <vector>
#include <time.h>
#include <cstdarg>
#include <stdlib.h>

//using std::vector;

namespace jep
{

	//Initializes random seed.
	void init()
	{
		srand(time(NULL));
	}

	//Returns true based on percent chance in decimal.
	bool booRoll(double chance)
	{
		if (chance >= 1)
			return true;

		if (chance == 0)
			return false;

		return (rand() % 1000 < chance * 1000);
	}

	//Returns a number between a range of two integers.
	int intRoll(int n1, int n2)
	{
		if (n1==n2)
			return n1;

		if (n1<n2)
			return n1 + (rand() % (1+n2-n1));

		if (n2<n1)
			return n2 + (rand() % (1+n1-n2));
	}

	//Takes a number of values (x), and returns a number from 0 to (x-1), with larger values having a proportionately
	//larger chance of rolling. Passing a vector containing ints 10, 20, and 70 would have a 10:100 chance to roll a 0, 
	//a 20:100 chance to roll a 1, and a 70:100 chance to roll a 2.
	/*
	int catRoll(vector <int> &chances)
	{
		int seedRange=0;

		//combines all numbers from chances
		for (int i=0; i<chances.size(); i++)
		{
			seedRange += chances.at(i);
		}

		//rolls random number between 1 and total from above
		int seed = jep::intRoll(1, seedRange);

		//cout << "jep::catRoll seed = " << seed << endl;

		vector <int> rangeCheck;

		//generates seed checklist
		for (int i=0; i<chances.size(); i++)
		{
			int numberToPush=0;

			for(int c=0; c<i+1; c++)
			{
				numberToPush += chances.at(c);
			}

			rangeCheck.push_back(numberToPush);
		}

		for (int i=0; i<rangeCheck.size(); i++)
		{
			if (seed <= rangeCheck.at(i))
				return i;
		}
	}
	*/

	int catRoll(int n, ...)
	{
		int ranges[n];

		int seedRange=0;

		va_list ratios;
		va_start (ratios, n);

		for (int i=0; i<n; i++)
		{
			seedRange += va_arg(ratios, int);
			ranges[i] = seedRange;
		}
		va_end (ratios);

		int seed = intRoll(1, seedRange);
		
		for (int i=0; i<n; i++)
		{
			if (seed <= ranges[i])
				return (i+1);
		}	
	}
}
