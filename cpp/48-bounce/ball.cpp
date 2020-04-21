#include<iostream>
#include<exception>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <cmath>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int n=0;
struct Ball {
	sf::Texture texture;
	sf::Sprite sprite;
	float radius;
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
		pos=sf::Vector2f(rand()%width+1, rand()%height+1);
		speed=sf::Vector2f(rand()%5-2, rand()%5-2);
	}

	// The sprite bounces between radius < x < 800-radius, etc.
	void checkBorderColision(){
		if(pos.x<radius||pos.x>(width -radius)) speed.x=-speed.x;
		if(pos.y<radius||pos.y>(height-radius)) speed.y=-speed.y;
	}

	// Two balls colliding require a treatment
	void checkBallColision(Ball& o){
		// Distance calculation
		double r=sqrt(pow(pos.x-o.pos.x, 2)+pow(pos.y-o.pos.y, 2));
		// Collision!
		if(r<radius*2) {
			std::cerr<<"Collision: #"<<id<<" - #"<<o.id<<"; D="<<r<<std::endl;
		}
	//		// Correct distance to avoid overlapping: move the other
	//		PVector distanceVectFixed=distanceVect.copy().normalize().mult(minDistance-distanceVect.mag());
	//		other.position.add(distanceVectFixed);
	//		// Rotate both speeds to emulate bouncing on a vertical wall
	//		velocity.rotate(-distanceVectFixed.heading());
	//		other.velocity.rotate(-distanceVectFixed.heading());
	//		// Then, simply exchange horizontal speeds
	//		float tempX = velocity.x;
	//		velocity.x = other.velocity.x;
	//		other.velocity.x = tempX;
	//		// Rotate back to original coordinates
	//		velocity.rotate(distanceVectFixed.heading());
	//		other.velocity.rotate(distanceVectFixed.heading());
	//		//calculateEntropy();
	//	}
	}

	// The position is the center of the sprite, so, (0, 0)
	// would mean only a quarter of the ball would be visible
	void update() {
		pos+=speed;
		sprite.setPosition(pos-sf::Vector2f(radius, radius));
	}
};

/*
bool collision(const sf::Sprite& ball1, const sf::Sprite& ball2) {
	sf::Vector2f ball1Size=getSpriteSize(ball1);
	sf::Vector2f ball2Size=getSpriteSize(ball2);
	float radius1=(ball1Size.x+ball1Size.y)/4;
	float radius2=(ball2Size.x+ball2Size.y)/4;
	sf::Vector2f Distance=getSpriteCenter(ball1)-getSpriteCenter(ball2);
	return (Distance.x*Distance.x+Distance.y*Distance.y<=(radius1+radius2)*(radius1+radius2));
}
*/
