#include <iostream>
#include <stdlib.h>
#include "jeploot.h"

int main(int argc, char** argv)
{
	jep::init();

	int boolcount=0;

	double chance=.5;
	for (int i=0; i<(atoi(argv[1])); i++)
	{
		if (jep::booRoll(chance)==true)
			boolcount++;
	}

	std::cout << "jep::boolRoll(" << chance << ") rolled true " << boolcount << " times out of " << (atoi(argv[1])) << " attempts." << std::endl;


	int rangelow=15;
	int rangehigh=89;
	std::cout << "jep::intRoll(" << rangelow << "," << rangehigh << ") rolled: ";
	for (int i=0; i<(atoi(argv[2])); i++)
	{
		std::cout << jep::intRoll(rangelow,rangehigh) << " ";
	}
	std::cout << std::endl;
	
	int cat[4] = { 10, 20, 70, 100 };
	std::cout << "jep::catRoll(4," << cat[0] << "," << cat[1] << ","  << cat[2] << ","  << cat[3] << ") rolled: ";
	for (int i=0; i<(atoi(argv[3])); i++)
	{
		std::cout << jep::catRoll(4, cat[0],cat[1],cat[2],cat[3]) << " ";
	}
	std::cout << std::endl;
}
