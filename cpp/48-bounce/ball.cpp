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
	size_t width, height;
public:
	Ball(sf::RenderWindow& win, float x, float y, float dx, float dy): app(win), pos(x, y), speed(dx, dy) {
		t2.loadFromFile("ball.png");
		sf::Sprite ball2(t2);
		this->ball=std::move(ball2);
		width=ball.getTextureRect().width;
		height=ball.getTextureRect().height;
	}
	void action() {
		pos+=speed;
		if(pos.x<0||pos.x>(800-width )) speed.x=-speed.x;
		if(pos.y<0||pos.y>(600-height)) speed.y=-speed.y;
		ball.setPosition(pos);
		app.draw(ball);
	}
};
