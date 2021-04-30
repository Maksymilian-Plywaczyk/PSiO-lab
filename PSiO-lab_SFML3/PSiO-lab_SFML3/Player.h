#pragma once


#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<memory>
#include	"Wall.h"


class Player:public sf::Sprite
{
	private:
		sf::Texture player_texture;
		sf::Vector2f position;
		sf::RectangleShape player;
		sf::Vector2f size;
		float speed_direction_x = 120;
		float speed_direction_y = 130;
		int left_bounds = 0;
		int width_bounds = 0;
		int top_bounds = 0;
		int height_bounds = 0;
	public:
		Player( sf::Vector2f & position_);
		void player_animate(sf::Time&elapsed);
		void set_bounds(int left,int width,int top, int height);
		void collision_detected(Wall wall);
		

};

