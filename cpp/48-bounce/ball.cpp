#include <iostream>
#include <exception>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "rixmath.h"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int n=0;
struct Ball {
	sf::Texture texture;
	sf::Sprite sprite;
	float radius, minDistance;
	sf::RenderWindow& win;
	int width, height;
	int id;
	sf::Vector2f pos, speed;

	// Constructors: only copies are initialized, check vector initialization method.
	Ball(sf::RenderWindow& win, int width, int height): win(win), width(width), height(height), id(n++) {}
	Ball(const Ball& b): win(b.win), width(b.width), height(b.height), id(n++) {
		texture.loadFromFile("ball.png");
		sprite=sf::Sprite(texture);
		radius=sprite.getTextureRect().width/2+1;
		minDistance=radius*2;
		//if(id==1) {
		//	pos=sf::Vector2f(200, 200);
		//	speed=sf::Vector2f(5, 0);
		//} else if (id==2) {
		//	pos=sf::Vector2f(600, 220);
		//	speed=sf::Vector2f(0, 0);
		//} else {
		float x=radius+1+rand()%(width -2*(int)radius);
		float y=radius+1+rand()%(height-2*(int)radius);
		pos=sf::Vector2f(x, y);
		speed=sf::Vector2f(rand()%5-2, rand()%5-2);
		//}
	}

	// Two balls colliding require a treatment
	void checkBallColision(Ball& o){
		// Positions, radius calculation
		sf::Vector2f distanceVect=o.pos-pos;
		float distanceVectMag=sfm::Length(distanceVect);

		// Collision!
		if(distanceVectMag<minDistance) {
			// Correct distance to avoid overlapping: move the other
			sf::Vector2f distanceVectFixed=sfm::Normalized(distanceVect)*(minDistance-distanceVectMag);
			o.pos+=distanceVectFixed;

			// Rotate both speeds to emulate bouncing on a vertical wall
			float angle=sfm::Angle(distanceVect);
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
	void checkBorderColision(){
		if(pos.x<radius||pos.x>(width -radius)) speed.x=-speed.x;
		if(pos.y<radius||pos.y>(height-radius)) speed.y=-speed.y;
	}

	// The position is the center of the sprite, so, (0, 0)
	// would mean only a quarter of the ball would be visible
	void update() {
		pos+=speed;
		sprite.setPosition(pos-sf::Vector2f(radius, radius));
	}
};
