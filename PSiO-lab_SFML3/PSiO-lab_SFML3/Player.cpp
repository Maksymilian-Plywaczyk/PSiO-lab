#include "Player.h"

Player::Player (sf::Vector2f& position_):position(position_) {
	
	this->setPosition(position);
	//this->player.setPosition(position);
	//this->setScale(size);
	this->player_texture.loadFromFile("rse/guy.png");
	auto textureSize = this->player_texture.getSize();

	this->setTexture(player_texture);


}
