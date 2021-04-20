#pragma once
//other option is use include guards by pragma once.
//#ifndef HEADER_H
//#define HEADER_H
// between define and endif here we put code.
//#endif //HEADER_H

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	<vector>

class CustomRectangle:public sf::RectangleShape
{
public:
	CustomRectangle(const sf::Vector2f& size, const sf::Vector2f& position);
	void setSpeed(int speed_of_direction_x_, int speed_of_direction_y_, int speed_of_rotate_);
	void rectangle_animate(sf::Time& elapsed);
	void setBounds(int left, int width, int top, int height);
	void setBounds(sf::IntRect& rectangle);
	void bounce();
	void select();
	void unselect();
private:
	sf::Vector2f size;
	sf::Vector2f position;
	int speed_of_direction_x = 0;
	int speed_of_direction_y = 0;
	int speed_of_rotate = 0;
	int left_bounds = 0;
	int width_bounds = 0;
	int top_bounds = 0;
	int height_bounds = 0;
	bool is_selected = false;

};

