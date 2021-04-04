#include <iostream>
#include "PSiO-lab3_functions.h"


int main()
{
    std::cout << "Hello World!\n";
    //exercise1(20,10);
   //exercise2(10,5);
   //exercise3(10,5);
    //exercise4(10);
  /*  exercise5(10);*/

    Basket koszyk;
    Basket koszyk2;
    put_vegetables_and_fruits(3,koszyk);
    put_vegetables_and_fruits(3, koszyk2);
    //sprawdzanie_gruszki(koszyk);
    //zlicz_warzywa(koszyk);
    //exercise10(koszyk);
    wspolne_rosliny(koszyk, koszyk2);
}