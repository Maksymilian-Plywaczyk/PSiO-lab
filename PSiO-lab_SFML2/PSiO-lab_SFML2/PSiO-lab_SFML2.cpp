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
   
    Traktor(const std::string& name,bool color) :Vehicle(name, 4, "Diesel", 100),color(color) {}
    bool has_color() { return color; }
private:
   bool color;
};

class CustomRectangleShape:public sf::RectangleShape
{
public:
    sf::Vector2f size;
    sf::Vector2f position;
    CustomRectangleShape(const sf::Vector2f& size_, const sf::Vector2f& position_) :size(size_), position(position_) {}
    sf::Vector2f sizeS() { return size; }
};

int main()
{
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape my_rectangle(size, position);
    my_rectangle.setFillColor(sf::Color(100, 50, 100));
    std::cout << my_rectangle.sizeS().x << std::endl;
    Traktor traktor("Wielki ciagnik",false);
    Car car("Toyota","Gasoline",200.0,false);
    std::cout << car.name()<<" "<<car.propulsion_type() << std::endl;
    std::cout << traktor.has_color() << std::endl;
  

   
    std::cout << "Hello World!\n";
}

