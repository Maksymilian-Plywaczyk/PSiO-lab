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
void exercise3(const int& range2, int erase_value_find)
{
	
	std::list<int>numbers1;
	for (int i = 0; i < range2; i++)
	{
		numbers1.push_back(randomInt(-20,20));
	}
	std::list<int>::iterator result = std::find(numbers1.begin(), numbers1.end(), erase_value_find);
	while (result != numbers1.end())
	{
		numbers1.erase(result);
		result = std::find(numbers1.begin(), numbers1.end(), erase_value_find);

	}		
	for (auto it = numbers1.begin(); it != numbers1.end(); it++)
	{
		std::cout << *it << " ";
	}
}
