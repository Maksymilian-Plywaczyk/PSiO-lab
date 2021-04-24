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
    std::vector<CustomRectangle>rectangles;
    for (int i = 0; i < 10; i++) {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangle(size, position));
    }

    for (auto& rec : rectangles) {
        rec.setFillColor(sf::Color(rand() % 255, rand() % 255, rand()%255));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) 
                {
                    my_rectangle.select();
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::B)
                {
                        my_rectangle.unselect();
                }
             }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                    
                }
            }
        }
        
        // logic of game 
        sf::Time elapsed = clock.restart();
        my_rectangle.rectangle_animate(elapsed);
        
        
        
        //clear the window with black screen
        window.clear(sf::Color::Black);
        window.draw(my_rectangle);
     /*   for (auto& r : rectangles)
        {
            r.rectangle_animate(elapsed);
            window.draw(r);
        }*/
        
       
        //end of current frame
        window.display();







    }
}


