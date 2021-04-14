#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

class Vehicle {
public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }
   
protected:
    Vehicle(const std::string& name, int number_of_wheels,
        const std::string& propulsion_type, double max_speed) 
        :name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};
class Bike :public Vehicle
{
   
protected:
    Bike() :Vehicle("bike", 2, "muscles", 30) {}

};
class Car :public Vehicle {
public:
    Car(const std::string& name, const std::string& propulsion_type, double max_speed, bool has_abs):Vehicle(name,4,propulsion_type,max_speed),has_abs_(has_abs){}
    bool has_abs() { return has_abs_; }
  
private:
    bool has_abs_;
};
class Traktor : public Vehicle
{
public:
    Traktor();
};

int main()
{
    Car car("Toyota","Gasoline",200.0,false);
    std::cout << car.name()<<" "<<car.propulsion_type() << std::endl;


   
    std::cout << "Hello World!\n";
}

