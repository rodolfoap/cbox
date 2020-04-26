#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.h"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

void Ball::init(int width, int height, sf::Texture& texture) {
	this->setTexture(texture);
	radius=getTextureRect().width/2;
	setOrigin(radius, radius);
	pos=sf::Vector2f(radius+1+rand()%(width -2*(int)radius), radius+1+rand()%(height-2*(int)radius));
	speed=sf::Vector2f(rand()%3-1, rand()%3-1);
}

// Updates only the local values, not the sprite
void Ball::updatePos(){
	pos+=speed;
}

// Applies the local pos value to the sprite
void Ball::move(){
	setPosition(pos);
}
