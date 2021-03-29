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

void exercise4(const int& range3)
{
	std::vector<int>numbers;
	for (int i = 0; i < range3; i++)
	{
		numbers.push_back(randomInt(-20, 20));
	}
	for (auto& n : numbers)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;
	const auto [min, max] = std::minmax_element(numbers.begin(), numbers.end());
	std::cout <<"Element najmniejszy: "<<*min <<"\nElement najwiekszy: "<<*max << std::endl;
}

void exercise5(const int& range4)
{
	std::vector<int>numbers;
	for (int i = 0; i < range4; i++)
	{
		numbers.push_back(randomInt(-20, 20));
	}
	std::sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
	for (auto& n : numbers)
	{
		std::cout << n << " ";
	}
}

void exercise6(const int& range5)
{
	std::vector<int>numbers;
	for (int i = 0; i < range5; i++)
	{
		numbers.push_back(randomInt(-20, 20));
	}
	for (auto& n : numbers)
	{
		int couting = std::count(numbers.begin(), numbers.end(), n);
		std::cout << "Number: " << n << " cout: " << couting << std::endl;
	}

}

void put_vegetables_and_fruits(int number,Basket basket)
{
	Plant plant;
	int rodzaj;
	for (int i = 0; i < number; i++)
	{
		std::cout << "What do you want to add: Vegetable press '1', Fruit press '2': ";
		std::cin >> rodzaj;
		switch (rodzaj)
		{
		case 1:
		{
			plant.typ = TypePlant::Vegetable;
			std::cout << "Enter the name of Vegetable: " << std::endl;
			std::cin >> plant.nazwa;
			basket.push_back(plant);
			break;
		}
		case 2:
		{
			plant.typ = TypePlant::Fruit;
			std::cout << "Enter the name of Fruit: " << std::endl;
			std::cin >> plant.nazwa;
			basket.push_back(plant);
			break;
		}

		}

	}
}

//std::ostream& operator<<(std::ostream& out, const Plant &plant)
//{
//	int typ,typ2;
//	 typ=static_cast<int>(plant.typ == TypePlant::Vegetable);
//	 typ2= static_cast<int>(plant.typ == TypePlant::Fruit);
//	 return out << typ << typ2;
//}
//std::ostream& operator<<(std::ostream& out, const Basket& basket)
//{
//	for (auto& full_basket : basket)
//	{
//		out << full_basket.nazwa<<
//	}
//}
//

bool czy_jest_gruszka(const Basket& basket)
{
	auto finding = std::find_if(basket.begin(), basket.end(), [](const Plant plant)
		{
			 plant.nazwa == "Gruszka";
			return true;
		});
	if (finding != std::end(basket))
	{
		return true;
	}else{ return false; }
		



}
void sprawdzanie_gruszki( Basket basket)
{
	if (czy_jest_gruszka(basket))
	{
		std::cout << "Jest gruszka w koszyku!";
	}
	else
		std::cout << "Nie ma gruszki";
}

