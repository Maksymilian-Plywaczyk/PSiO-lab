#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Grass.h"
#include "Wall.h"
#include <memory>


int main()
{
    srand(std::time(0));
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(700, 800), "WELCOME TO SFML");
    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f player_position(300.0, 400.0);
    sf::Vector2f grass_position(0,0);
    Player player(player_position);
    player.set_bounds(0, window.getSize().x, 0, window.getSize().y);

    sf::IntRect wall_size(20, 20, rand() % 200, rand() % 200);
    sf::Vector2f wall_position(200.0, 200.0);
    Wall wall(wall_position, wall_size);
    
    Grass grass(grass_position, window.getSize().x, window.getSize().y);
    
    window.setFramerateLimit(60);
    
    
    sf::IntRect wall_size_(40, 40, 100, 100);
    sf::Vector2f wall_position1(rand() % 700, rand() % 800);

    //TO DO sprawdz czy vector<Wall*> zadziała bez smart pointersów.
    std::vector<Wall*>walls;
    std::vector<Wall*>walls2;
    for (int i = 0; i < 5; ++i)
    {
        sf::IntRect wall_size_(40, 40, 150, 40);
        sf::Vector2f wall_position1(rand() % 500, rand() % 500);
        walls.emplace_back(new Wall(wall_position1, wall_size_));
    }
    for (int i = 0; i < 5; ++i)
    {
        sf::IntRect wall_size_(0, 0, 40, 150);
        sf::Vector2f wall_position1(rand() % 500, rand() % 500);
        walls2.emplace_back(new Wall(wall_position1, wall_size_));
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.restart();
        player.player_animate(elapsed,wall);
     
        window.clear();
        window.draw(grass);
        for (auto& w : walls)
        {
            w->wall_drawing(window);
        }
        for (auto& w : walls2)
        {
            w->wall_drawing(window);
        }
        //wall.wall_drawing(window);
        window.draw(player);
        window.display();
    }

    return 0;
}