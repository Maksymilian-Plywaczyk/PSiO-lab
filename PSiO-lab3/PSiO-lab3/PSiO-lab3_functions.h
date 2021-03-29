#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <list>
#include<algorithm>
#include <ostream>

int randomInt(int min, int max);
void exercise1(const int& range,   int erase_value);
void exercise2(const int& range_list, int erase_value_list);
void exercise3(const int& range2, int erase_value_find);
void exercise4(const int& range3);
void exercise5(const int& range4);
void exercise6(const int& range5);

enum class TypePlant { Fruit, Vegetable };

struct Plant {
    TypePlant typ;
    std::string nazwa;
};
using Basket = std::vector<Plant>;
void put_vegetables_and_fruits(int number,Basket basket);
std::ostream& operator<<(std::ostream& out, const Plant &plant);
std::ostream& operator<<(std::ostream& out, const Basket& basket);
bool czy_jest_gruszka(const Basket& basket);
void sprawdzanie_gruszki(Basket basket);