#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>


void create_shapes(sf::Time& elapsed,sf::RenderWindow& window,std::vector<std::unique_ptr<sf::Drawable>>&shapes)
{
   //circle
    auto circle = std::make_unique<sf::CircleShape>(100.0f);
    circle->setPosition(100.0f, 300.0f);
    circle->setFillColor(sf::Color(100, 250, 50));
    
    //rectangle    
    auto rectangle=std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(200.0, 400.0);
    rectangle->setFillColor(sf::Color(100, 50, 250));
    
    //triangle
    auto triangle = std::make_unique<sf::ConvexShape>();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);
    


    float rectangle_velocity_x = 50;
    float rectangle_velocity_y = 150;
    float rectangle_angular_velocity = 10;


    //rectangle->move(rectangle_velocity_x * elapsed.asSeconds(), rectangle_velocity_y * elapsed.asSeconds());
    //rectangle->rotate(rectangle_angular_velocity * elapsed.asSeconds());


    sf::FloatRect rectangle_bounds = rectangle->getGlobalBounds();
    std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " ";
    std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;
    if (rectangle_bounds.top <= 0)
    {
        rectangle_velocity_y = std::abs(rectangle_velocity_y);

        rectangle->setFillColor(sf::Color(255, 255, 0));
    }

    if (rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y)
    {

        rectangle_velocity_y = -std::abs(rectangle_velocity_y);

        rectangle->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }
    if (rectangle_bounds.left <= 0)
    {
        rectangle_velocity_x = std::abs(rectangle_velocity_x);

        rectangle->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }
    if (rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x)
    {
        rectangle_velocity_x = -std::abs(rectangle_velocity_x);
        rectangle->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

    }
    shapes.push_back(std::move(circle));
    shapes.push_back(std::move(rectangle));
    shapes.push_back(std::move(triangle));

}


int main() {
    // create the window
     
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  
    sf::Clock clock;

    window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen()) {
  
      
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //LOGIKA
       
        sf::Time currentTime = clock.restart(); 
        std::vector<std::unique_ptr<sf::Drawable>> shapes;
        create_shapes(currentTime, window,shapes);
       
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for (const auto& s : shapes) {
            window.draw(*s);
        }
      //std::cout << " " << distance_x << " " << distance_y << std::endl;
       //std::cout << fps << std::endl;
        // end the current frame
        window.display();
    }

    return 0;
}