#pragma once


#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<memory>


class Wall 
{
	private:
		sf::Sprite wall;
		sf::Texture wall_texture;
		//sf::Texture wall_texture;
		sf::IntRect wall_size;
		sf::Vector2f position_wall;
	public:
		Wall(sf::Vector2f& position_wall_,sf::IntRect& wall_size_);
		void wall_drawing(sf::RenderWindow& window);
		sf::FloatRect wall_bounds();

};

