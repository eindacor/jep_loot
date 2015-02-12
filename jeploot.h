#include <vector>
#include <map>

namespace jep
{
	void init();
	bool booRoll(double chance);
	int intRoll(int n1, int n2);
	int catRoll(int n, ...);

	template <typename T>
	const T catRoll(const std::map<T, signed short> &m)
	{
		std::vector<signed short> ranges;
		int seedRange = 0;

		for (std::map<T, signed short>::const_iterator it = m.begin(); it != m.end(); it++)
		{
			seedRange += it->second;
			ranges.push_back(seedRange);
		}

		int random_number = rand() % seedRange;

		std::map<T, signed short>::const_iterator to_return = m.begin();
		for (std::vector<signed short>::const_iterator it = ranges.begin(); it != ranges.end(); it++)
		{
			if (random_number < (*it))
				return ((*to_return).first);

			to_return++;
		}
	}
}
