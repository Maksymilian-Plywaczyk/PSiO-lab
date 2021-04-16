#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include "CustomRectangle.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "Window");
    sf::Clock clock;

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    sf::IntRect rect1(10, 10, 200, 100);
    CustomRectangle my_rectangle(size, position);
    my_rectangle.setFillColor(sf::Color(100, 50, 100));
    my_rectangle.setSpeed(100, 100, 50);
    my_rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);
    //sf::IntRect rect1(10, 10, 200, 100);
    
    window.setFramerateLimit(60); //set Frame per second to 60.
    
   

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        // logic of game 
        sf::Time elapsed = clock.restart();
        my_rectangle.rectangle_animate(elapsed);
        
        
        
        //clear the window with black screen
        window.clear(sf::Color::Black);
        
        
       
        //end of current frame
        window.display();







    }
}


