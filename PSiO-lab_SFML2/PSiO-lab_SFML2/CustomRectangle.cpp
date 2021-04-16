#include "CustomRectangle.h"



CustomRectangle::CustomRectangle(const sf::Vector2f& size_, const sf::Vector2f& position_):size(size_),position(position_),RectangleShape(size_)
{
	this->setPosition(position);
}

void CustomRectangle::setSpeed(int speed_of_direction_x_, int speed_of_direction_y_, int speed_of_rotate_)
{
	this->speed_of_direction_x = speed_of_direction_x_;
	this->speed_of_direction_y = speed_of_direction_y_;
	this->speed_of_rotate = speed_of_rotate_;
}
void CustomRectangle::rectangle_animate(sf::Time& elapsed)
{
	//moving of rectangle 
	move(speed_of_direction_x * elapsed.asSeconds(),speed_of_direction_y*elapsed.asSeconds());

	//rotating of rectangle
	rotate(speed_of_rotate * elapsed.asSeconds());
	bounce();
}

void CustomRectangle::setBounds(int left, int width, int top, int height)//method of set limits of area
{
	this->left_bounds = left;  
	this->width_bounds = width;
	this->top_bounds = top;
	this->height_bounds = height;
}

void CustomRectangle::setBounds(sf::IntRect& rectangle)// second method of set limits of area, support IntRect
{
	//it is copy of setBounds up, let do it quickly.
	//this->left_bounds = rectangle.left;
	//this->width_bounds = rectangle.width;
	//this->top_bounds = rectangle.top;
	//this->height_bounds = rectangle.height;

	//take setBounds method, assign intRect rectangle values.
	setBounds(rectangle.left, rectangle.left + rectangle.width, rectangle.top, rectangle.top + rectangle.height);
}

void CustomRectangle::bounce()
{
	sf::FloatRect rectangle_bounds = getGlobalBounds();

	if (rectangle_bounds.left <= left_bounds)
	{
		speed_of_direction_x = std::abs(speed_of_direction_x);
	}
	if (rectangle_bounds.left + rectangle_bounds.width >= width_bounds)
	{
		speed_of_direction_x = -std::abs(speed_of_direction_x);
	}
	if (rectangle_bounds.top <= top_bounds)
	{
		speed_of_direction_y = std::abs(speed_of_direction_y);
	}
	if (rectangle_bounds.top + rectangle_bounds.height >= height_bounds)
	{
		speed_of_direction_y = -std::abs(speed_of_direction_y);
	}
}

