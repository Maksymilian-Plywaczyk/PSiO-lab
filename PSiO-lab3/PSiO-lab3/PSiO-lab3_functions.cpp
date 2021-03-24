#include "PSiO-lab3_functions.h"


int randomInt(int min, int max)
{
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}
void exercise1(const int& range,  int erase_value)
{
	std::vector<int>numbers;
	for (int i = 0; i < range; i++)
	{
		numbers.push_back(randomInt(-20, 20));
		
	}
	
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		if (*it == erase_value)
		{
			it= numbers.erase(it);
		}
		it++;
	}
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		
		std::cout << *it << std::endl;
	}


}
void exercise2(const int& range_list, int erase_value_list)
{
	std::list<int>numbers;
	
	for (int i = 0; i < range_list; i++)
	{
		numbers.push_back(randomInt(-20, 20));
	}
	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		if (*it == erase_value_list)
		{
			it = numbers.erase(it);
		}
		it++;
	}
	for (auto it = numbers.begin(); it != numbers.end();it++)
	{
		
		std::cout << *it<<" ";
	}
	
	
}