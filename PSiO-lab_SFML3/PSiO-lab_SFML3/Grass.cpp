#include "Grass.h"

Grass::Grass(sf::Vector2f& position_, float scale_x_, float scale_y_) :position(position_),scale_x(scale_x_),scale_y(scale_y_){

	this->setPosition(position);
	//this->setScale(100, 100);
	this->grass_texture.loadFromFile("rse/grass.png");
	auto textureSize = this->grass_texture.getSize();

	this->setTexture(grass_texture);
	
}
//
//void Grass::setScale(float scale_x_, float scale_y_) {
//	this->scale_x = scale_x_;
//	this->scale_y = scale_y_;
//
//
//	this->setScale(scale_x_ /this->getLocalBounds().width, scale_y_ / this->getLocalBounds().height);
//	
//}
