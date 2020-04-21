#include<iostream>
#include<exception>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class Ball {
private:
	sf::Texture texture;
	sf::Sprite ball;
	sf::Vector2f pos, speed;
	float radius;
	sf::RenderWindow& win;
public:
//	Ball(sf::RenderWindow& win, float x, float y, float dx, float dy): win(win), pos(x, y), speed(dx, dy) {
	Ball(sf::RenderWindow& win): win(win) { init(); }
	Ball(const Ball& old):       win(win) { init(); }
	void init(){
		texture.loadFromFile("ball.png");
		ball=sf::Sprite(texture);
		radius=ball.getTextureRect().width/2+1;
	}
	void setConfig(float x, float y, float dx, float dy){
		pos.x=x;
		pos.y=y;
		speed.x=dx;
		speed.y=dy;
	}
	void checkBorderColision(){
		// The sprite bounces between radius < x < 800-radius
		if(pos.x<radius||pos.x>(800-radius)) speed.x=-speed.x;
		if(pos.y<radius||pos.y>(600-radius)) speed.y=-speed.y;
	}
	void checkBallColision(Ball& other){
		//sf::Vector2f distance=
	//	PVector distanceVect = PVector.sub(other.position, position);
	//	float distanceVectMag = distanceVect.mag();
	//	if (distanceVectMag < minDistance) {	// Collision!
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
	sf::Sprite& getsprite(){
		return ball;
	}
	void update() {
		pos+=speed;
//	float r=static_cast<float>(rand())/static_cast<float>(RAND_MAX);
		// The position is the center of the sprite, so (0,0)
		// would mean only a quarter of the ball would be visible
		ball.setPosition(pos-sf::Vector2f(radius, radius));
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
