#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Grass.h"


int main()
{
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(700, 800), "WELCOME TO SFML");
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f player_position(300.0, 400.0);
    sf::Vector2f grass_position(window.getSize().x / 2, window.getSize().y / 2);
    Player player(player_position);
    
    Grass grass(grass_position, window.getSize().x, window.getSize().y);
    player.set_bounds(0,700,0 ,800);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.restart();
        player.player_animate(elapsed);
        window.clear();
        window.draw(player);
        window.draw(grass);

        window.display();
    }

    return 0;
}