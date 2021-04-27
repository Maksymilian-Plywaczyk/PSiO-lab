#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(700, 800), "WELCOME TO SFML");
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(300.0, 400.0);
    Player player(position);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(player);

        window.display();
    }

    return 0;
}