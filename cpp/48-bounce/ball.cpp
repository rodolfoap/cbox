#include <iostream>
#include <exception>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "rixmath.h"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

struct Ball {
	sf::Texture texture;
	sf::Sprite sprite;
	float radius, minDistance;
	sf::RenderWindow& win;
	int width, height;
	sf::Vector2f pos, speed;

	// Constructors: only copies are initialized, check vector initialization method.
	Ball(sf::RenderWindow& win, int width, int height): win(win), width(width), height(height) {}
	Ball(const Ball& b): win(b.win), width(b.width), height(b.height) {
		texture.loadFromFile("ball96.png");
		sprite=sf::Sprite(texture);
		radius=sprite.getTextureRect().width/2;
		minDistance=radius*2;
		pos=sf::Vector2f(radius+1+rand()%(width -2*(int)radius), radius+1+rand()%(height-2*(int)radius));
		speed=sf::Vector2f(rand()%5-2, rand()%5-2);
	}

	// Two balls colliding require a treatment
	void checkBallColision(Ball& o) {
		// Positions, radius calculation
		sf::Vector2f segment=o.pos-pos;
		float segmentLen=sfm::Length(segment);
		// Collision!
		if(segmentLen<minDistance) {
			// Correct distance to avoid overlapping: move myself
			sf::Vector2f segmentDelta=sfm::Normalized(segment)*(minDistance-segmentLen);
			pos-=segmentDelta;
			// Correct distance to avoid overlapping: move the other
			o.pos+=segmentDelta;
			// Rotate both speeds to emulate bouncing on a vertical wall
			float angle=sfm::Angle(segment);
			sfm::Rotate(speed, -angle);
			sfm::Rotate(o.speed, -angle);
			// Then, simply exchange horizontal speeds
			std::swap(o.speed.x, speed.x);
			// Rotate back to original coordinates
			sfm::Rotate(speed, angle);
			sfm::Rotate(o.speed, angle);
		}
	}

	// The sprite bounces between radius < x < 800-radius, etc.
	void checkBorderColision() {
		if(pos.x<radius)        { pos.x=radius;        speed.x=-speed.x; }
		if(pos.x>width-radius)  { pos.x=width-radius;  speed.x=-speed.x; }
		if(pos.y<radius)        { pos.y=radius;        speed.y=-speed.y; }
		if(pos.y>height-radius) { pos.y=height-radius; speed.y=-speed.y; }
	}

	// The position is the center of the sprite, so, (0, 0)
	// would mean only a quarter of the ball is visible
	void update() {
		pos+=speed;
	}

	// The position is the center of the sprite, so, (0, 0)
	// would mean only a quarter of the ball is visible
	void move() {
		sprite.setPosition(pos-sf::Vector2f(radius, radius));
	}
};
