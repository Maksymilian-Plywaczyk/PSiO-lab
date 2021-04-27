#pragma once


#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<memory>


class Player:public sf::Sprite
{
	private:
		sf::Texture player_texture;
		sf::Vector2f position;
		sf::RectangleShape player;
		sf::Vector2f size;

	public:
		Player( sf::Vector2f & position_);
		

};

