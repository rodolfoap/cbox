#include <iostream>
#include <exception>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/rotate_vector.hpp> 
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int n=0;
struct Ball {
	// Two balls colliding require a treatment
	void checkBallColision(Ball& o){
		// Positions, radius calculation
		glm::vec2 distanceVect=o.pos-pos;
		float distanceVectMag=glm::length(distanceVect);

		// Collision!
		if(distanceVectMag<minDistance) {
			std::cerr<<"Collision: #"<<id<<" - #"<<o.id<<"; D="<<distanceVectMag<<"; P="<<distanceVect.x<<":"<<distanceVect.y<<std::endl;
			// Correct distance to avoid overlapping: move the other
			glm::vec2 distanceVectFixed=distanceVect;
			glm::normalize(distanceVectFixed);
			distanceVectFixed=distanceVectFixed*(minDistance-distanceVectMag);
			o.pos+=distanceVectFixed;

			// Rotate both speeds to emulate bouncing on a vertical wall
			float angle=glm::angle(distanceVect, glm::vec2(1,0));
			std::cerr<<"Angle: "<<angle<<std::endl;
			glm::rotate(speed, -angle);
			glm::rotate(o.speed, -angle);

			// Then, simply exchange horizontal speeds
			std::swap(o.speed.x, speed.x);

			// Rotate back to original coordinates
			glm::rotate(speed, angle);
			glm::rotate(o.speed, angle);
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
		sprite.setPosition(pos.x-radius, pos.y-radius);
	}

	sf::Texture texture;
	sf::Sprite sprite;
	float radius, minDistance;
	sf::RenderWindow& win;
	int width, height;
	int id;
	glm::vec2 pos, speed;

	// Constructors: only copies are initialized, check vector initialization method.
	Ball(sf::RenderWindow& win, int width, int height): win(win), width(width), height(height), id(n++) {}
	Ball(const Ball& b): win(b.win), width(b.width), height(b.height), id(n++) {
		texture.loadFromFile("ball96.png");
		sprite=sf::Sprite(texture);
		radius=sprite.getTextureRect().width/2+1;
		minDistance=radius*2;
		if(id==1) {
			pos=glm::vec2(200, 200);
			speed=glm::vec2(2, 0);
		} else if (id==2) {
			pos=glm::vec2(600, 220);
			speed=glm::vec2(0, 0);
		} else {
			pos=glm::vec2(rand()%width+1, rand()%height+1);
			speed=glm::vec2(rand()%5-2, rand()%5-2);
		}
	}

};
