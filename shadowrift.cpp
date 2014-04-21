#include <iostream>
#include "jeploot.h"
#include <vector>
#include <string>


void printCards(std::vector<int> actions, std::vector<int> loot, std::vector<int> attacks, std::vector<int> skills)
{
	for (int i=0; i<actions.size(); i++)
	{
		if (i==actions.begin())
			std::cout << "Actions: ";

		std::string toPrint;

		switch (actions.at(i))
		{
			case 0: toPrint = "Heal";
				break;

			case 1: toPrint = "Prophecy";
				break;

			case 2: toPrint = "Ressurrect";
				break;

			case 3: toPrint = "Revitalize";
				break;

			case 4: toPrint = "Rousing Speech";
				break;

			default: std::cout << "An error has occurred." << endl;
				break;
		}

		std::cout << toPrint;

		int last = actions.size();
		--last;

		if (i==last)
			std::cout << std::endl;

		else std::cout << " ,";
	}

	for (int i=0; i<loot.size(); i++)
	{
		if (i==loot.begin())
			std::cout << "Loot: ";

		std::string toPrint;

		switch (loot.at(i))
		{
			case 5: toPrint = "Armor of Mist";
				break;

			case 6: toPrint = "Elixir of Life";
				break;

			case 7: toPrint = "Lightning Daggers";
				break;

			case 8: toPrint = "Shining Blade";
				break;

			default: std::cout << "An error has occurred." << endl;
				break;
		}

		std::cout << toPrint;

		int last = loot.size();
		--last;

		if (i==last)
			std::cout << std::endl;

		else std::cout << " ,";
	}

	for (int i=0; i<attacks.size(); i++)
	{
		if (i==attacks.begin())
			std::cout << "Attacks: ";

		std::string toPrint;

		switch (attacks.at(i))
		{
			case 9: toPrint = "Blessed Smite";
				break;

			case 10: toPrint = "Fireball";
				break;

			case 11: toPrint = "Leading Strike";
				break;

			case 12: toPrint = "Spear Volley";
				break;

			case 13: toPrint = "Thieving Strike";
				break;

			case 14: toPrint = "Wild Charge";
				break;

			default: std::cout << "An error has occurred." << endl;
				break;
		}

		std::cout << toPrint;

		int last = attacks.size();
		--last;

		if (i==last)
			std::cout << std::endl;

		else std::cout << " ,";
	}

	for (int i=0; i<skills.size(); i++)
	{
		if (i==skills.begin())
			std::cout << "Skills: ";

		std::string toPrint;

		switch (skills.at(i))
		{
			case 0: toPrint = "Bamboozle";
				break;

			case 1: toPrint = "Brawler";
				break;

			case 2: toPrint = "Flanking";
				break;

			case 3: toPrint = "Frenzy";
				break;

			case 4: toPrint = "Holy Aura";
				break;

			default: std::cout << "An error has occurred." << endl;
				break;
		}

		std::cout << toPrint;

		int last = skills.size();
		--last;

		if (i==last)
			std::cout << std::endl;

		else std::cout << " ,";
	}
}


int main(int argc, char** argv)
{
	jep::init();
	
	int enemy_faction = jep::intRoll(0, 5);

	string faction_name;

	std::vector<int> cards_drawn;

	std::vector<int> actions;
	std::vector<int> loot;
	std::vector<int> attacks;
	std::vector<int> skills;

	switch(enemy_faction)
	{
		case 0: faction_name = "Storm Lords";
			break;

		case 1: faction_name = "Glacien";
			break;

		case 2: faction_name = "Fire Dragons";
			break;

		case 3: faction_name = "Drow";
			break;

		case 4: faction_name = "Demons";
			break;

		case 5: faction_name = "Necromancers";
			break;

		default: std::cout << "An error has occurred." << std::endl;
			break;
	}
		
	if (argc > 1 && argv[1] == "random")
	{
		for (int c=0; c<8; c++)
		{
			bool taken=false;
			int drawn;

			do
			{
				taken = false;
				drawn = jep::intRoll(0, 19);
				
				for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
				{
					if (drawn==(*i))
					{
						taken=true;
					}
				}

			} while (taken==true)

			cards_drawn.push_back(drawn);

			if (drawn>=0 && drawn<=4)
				actions.push_back(drawn);

			if (drawn>=5 && drawn<=8)
				loot.push_back(drawn);

			if (drawn>=9 && drawn<=14)
				attacks.push_back(drawn);

			if (drawn>=15 && drawn<=19)
				skills.push_back(drawn);	
		}
	}

	else if (argc > 1 && argv[1] == "even")
	{
		for (int c=0; c<8; c++)
		{
			bool taken=false;
			int drawn;

			if (c==0 || c==1)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(0, 4);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				actions.push_back(drawn);
			}

			if (c==2 || c==3)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(5, 8);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				loot.push_back(drawn);
			}

			if (c==4 || c==5)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(9, 14);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				attacks.push_back(drawn);
			}

			if (c==6 || c==7)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(15, 19);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				attacks.push_back(drawn);
			}
	
		}
	}

	else
	{
		for (int c=0; c<8; c++)
		{
			bool taken=false;
			int drawn;

			if (c==0)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(0, 4);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				actions.push_back(drawn);
			}

			else if (c==1)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(5, 8);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				loot.push_back(drawn);
			}

			else if (c==2)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(9, 14);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				attacks.push_back(drawn);
			}

			else if (c==3)
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(15, 19);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);
				attacks.push_back(drawn);
			}
	
			else
			{
				do
				{
					taken = false;
					drawn = jep::intRoll(0, 19);
				
					for (std::vector<int>::iterator i = cards_drawn.begin(); i!=cards_drawn.end(); i++)
					{
						if (drawn==(*i))
						{
							taken=true;
						}
					}

				} while (taken==true)

				cards_drawn.push_back(drawn);

				if (drawn>=0 && drawn<=4)
					actions.push_back(drawn);

				if (drawn>=5 && drawn<=8)
					loot.push_back(drawn);

				if (drawn>=9 && drawn<=14)
					attacks.push_back(drawn);

				if (drawn>=15 && drawn<=19)
					skills.push_back(drawn);
			}
	
		}
	}

	cout << "Enemy type: " << faction_name << std::endl;
	printCards(actions, loot, attacks, skills);

	return 0;
}
