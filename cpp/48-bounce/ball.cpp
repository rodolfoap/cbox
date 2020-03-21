#include<iostream>
#include<exception>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class Ball {
private:
	sf::Texture t2;
	sf::Sprite ball;
	sf::RenderWindow& app;
	sf::Vector2<float> pos, speed;
	float radius;
public:
//	Ball(sf::RenderWindow& win, float x, float y, float dx, float dy): app(win), pos(x, y), speed(dx, dy) {
	Ball(sf::RenderWindow& win): app(win) {
		t2.loadFromFile("ball.png");
		sf::Sprite ball2(t2);
		this->ball=std::move(ball2);
		radius=ball.getTextureRect().width/2+1;
	}
	void setConfig(float x, float y, float dx, float dy){
		pos.x=x;
		pos.y=y;
		speed.x=dx;
		speed.y=dy;
	}
	void update() {
		pos+=speed;
		float r=static_cast<float>(rand())/static_cast<float>(RAND_MAX);
		// The sprite bounces between radius < x < 800-radius
		if(pos.x<radius||pos.x>(800-radius)) speed.x=-speed.x;
		if(pos.y<radius||pos.y>(600-radius)) speed.y=-speed.y;
		// The position is the center of the sprite
		ball.setPosition(pos-sf::Vector2f(radius,radius));
		app.draw(ball);
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
