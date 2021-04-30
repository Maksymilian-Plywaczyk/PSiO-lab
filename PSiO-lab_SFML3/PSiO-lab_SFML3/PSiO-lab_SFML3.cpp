#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Grass.h"
#include "Wall.h"


int main()
{
    srand(std::time(0));
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(700, 800), "WELCOME TO SFML");
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f player_position(300.0, 400.0);
    sf::Vector2f grass_position(0,0);
    Player player(player_position);
    sf::IntRect wall_size(20, 20, rand() % 200, rand() % 200);
    sf::Vector2f wall_position(200.0, 200.0);
    Wall wall(wall_position, wall_size);
    Grass grass(grass_position, window.getSize().x, window.getSize().y);
    player.set_bounds(0,window.getSize().x,0 ,window.getSize().y);
    window.setFramerateLimit(60);
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
        player.collision_detected(wall);
        window.draw(grass);
        wall.wall_drawing(window);// to set background simply draw grass before player
        window.draw(player);
        window.display();
    }

    return 0;
}