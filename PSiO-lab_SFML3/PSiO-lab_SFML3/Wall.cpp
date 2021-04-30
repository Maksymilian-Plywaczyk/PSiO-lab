#include "Wall.h"

Wall::Wall(sf::Vector2f& position_wall_, sf::IntRect& wall_size_) : position_wall(position_wall_), 
wall_size(wall_size_)

{
	this->wall.setPosition(position_wall);
	if (!this->wall_texture.loadFromFile("rse/wall.png")) {
		std::cout << "Nie wczytano";
	}
	else
		std::cout << "wczytano" << std::endl;
	auto textureSize =this-> wall_texture.getSize();
	this->wall.setTexture(wall_texture);
	this->wall.setTextureRect(wall_size);

	std::cout << wall_texture.getSize().x << wall_texture.getSize().y << std::endl;
	//wall.setTextureRect(wall_size);

}

void Wall::wall_drawing(sf::RenderWindow& window)
{
	window.draw(wall);
}


