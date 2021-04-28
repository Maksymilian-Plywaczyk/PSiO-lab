#include "Player.h"

Player::Player (sf::Vector2f& position_):position(position_) {
	
	this->setPosition(position);
	//this->player.setPosition(position);
	//this->setScale(size);
	this->player_texture.loadFromFile("rse/guy.png");
	auto textureSize = this->player_texture.getSize();

	this->setTexture(player_texture);
	auto size_texture = this->getTexture()->getSize().x;
	//std::cout << size_texture << std::endl;
}

void Player::set_bounds(int left,int width,int top,int height)
{
	this->left_bounds = left;
	this->width_bounds = width;
	this->height_bounds = height;
	this->top_bounds = top;
}

void Player::player_animate(sf::Time& elapsed)
{
	sf::FloatRect player_bounds =getGlobalBounds();
	//std::cout << getGlobalBounds().left << std::endl;
	//std::cout << getGlobalBounds().top << std::endl;
	std::cout << getGlobalBounds().width + getGlobalBounds().left << " " << player_bounds.top + player_bounds.height << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (player_bounds.left > left_bounds)
			this->move(-speed_direction_x * elapsed.asSeconds(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (player_bounds.top > top_bounds)
			this->move(0, -speed_direction_y * elapsed.asSeconds());
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
	 if (player_bounds.left + player_bounds.width < width_bounds)
			this->move(speed_direction_x * elapsed.asSeconds(), 0);
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (player_bounds.top+player_bounds.height <height_bounds)
			this->move(0, speed_direction_y * elapsed.asSeconds());
		
	}
}
	

//void Player::collision_detected()
//{
//	sf::FloatRect player_bounds = sf::Sprite::getGlobalBounds();
//	if (player_bounds.left <= left_bounds) {
//		this->move(0, 0);
//	}
//	if (player_bounds.left + player_bounds.width >= width_bounds)
//	{
//		this->move(0, 0);
//	}
//	if (player_bounds.top <= top_bounds)
//	{
//		this->move(0, 0);
//	}
//	if (player_bounds.top + player_bounds.height >= height_bounds)
//	{
//		this->move(0, 0);
//	}
//}

