#pragma once


#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<memory>


class Grass:public sf::Sprite
{	
	private:
	sf::Texture grass_texture;
	sf::Vector2f  position;
	float scale_x;
	float scale_y;
	

	public:
		Grass(sf::Vector2f& position_,float scale_x_,float scale_y_);
		//void setScale(float scale_x_, float scale_y_);


};

