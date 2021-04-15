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
  
    CustomRectangleShape(const sf::Vector2f& size_, const sf::Vector2f& position_) :size(size_), position(position_) {}
    sf::Vector2f size_of_rectangle() { return size; }
  void setSpeed(int speed_of_direction_x_, int speed_of_direction_y_,int speed_of_rotate_) {
         this->speed_of_direction_x = speed_of_direction_x_;
         this->speed_of_direction_y = speed_of_direction_y_;
         this->speed_of_rotate = speed_of_rotate_;
       
    }
  void animate(sf::Time& elapsed)
  {
      move(speed_of_direction_x * elapsed.asSeconds(), speed_of_direction_y * elapsed.asSeconds());
      rotate(speed_of_rotate * elapsed.asSeconds());
  }
private:
    sf::Vector2f size;
    sf::Vector2f position;
    int speed_of_direction_x = 0;
    int speed_of_direction_y = 0;
    int speed_of_rotate = 0;
    
};

int main()
{
    sf::Clock clock;
    //inheritance in sfml
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape my_rectangle(size, position);
    my_rectangle.setFillColor(sf::Color(100, 50, 100));
    my_rectangle.setSpeed(100, 100, 50);
    sf::Time elapsed = clock.restart();
    my_rectangle.animate(elapsed);


  
    std::cout <<"Direction x:"<< my_rectangle.size_of_rectangle().x <<" direction y:" <<my_rectangle.size_of_rectangle().y<<std::endl;
    
    
    
    
    //Learing about inheritance in cpp, code some examples
    Traktor traktor("Wielki ciagnik",false);
    Car car("Toyota","Gasoline",200.0,false);
    std::cout << car.name()<<" "<<car.propulsion_type() << std::endl;
    std::cout << traktor.has_color() << std::endl;
  

   
    std::cout << "Hello World!\n";
}

