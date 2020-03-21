#include<iostream>
#include<exception>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
sf::Event e;

/*
sf::Vector2f getSpriteSize(const sf::Sprite& ball) {
	sf::IntRect size=ball.getTextureRect();
	sf::Vector2f scale=ball.getScale();
	return sf::Vector2f(size.width*scale.x, size.height*scale.y);
}
sf::Vector2f getSpriteCenter(const sf::Sprite& ball) {
	sf::FloatRect aabb=ball.getGlobalBounds();
	return sf::Vector2f(aabb.left+aabb.width/2.f, aabb.top+aabb.height/2.f);
}

bool collision(const sf::Sprite& ball1, const sf::Sprite& ball2) {
	sf::Vector2f ball1Size=getSpriteSize(ball1);
	sf::Vector2f ball2Size=getSpriteSize(ball2);
	float radius1=(ball1Size.x+ball1Size.y)/4;
	float radius2=(ball2Size.x+ball2Size.y)/4;
	sf::Vector2f Distance=getSpriteCenter(ball1)-getSpriteCenter(ball2);
	return (Distance.x*Distance.x+Distance.y*Distance.y<=(radius1+radius2)*(radius1+radius2));
}
*/
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

int main() {
	// Open window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar||sf::Style::Close);
	app.setFramerateLimit(60);
	// Background
	sf::Texture t1;
	if (!t1.loadFromFile("background.jpg")) return EXIT_FAILURE;
	sf::Sprite background(t1);
	app.clear();
	app.draw(background);
	app.display();
	Ball ball1(app, 300, 300, 4, 5);
	Ball ball2(app, 300, 300, 4, 6);
	// Game loop
	while (app.isOpen()) {
		while (app.pollEvent(e)) if(e.type==sf::Event::Closed) app.close();
		// Screen setup
		app.clear();
		app.draw(background);
		ball1.action();
		ball2.action();
		app.display();
	}
	return EXIT_SUCCESS;
}
