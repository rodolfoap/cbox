#include <iostream>
#include <exception>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.cpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
sf::Event e;

int main() {
	// Open window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar||sf::Style::Close);
	app.setFramerateLimit(60);
	Ball ball1(app, 300, 300, 4, 5);
	Ball ball2(app, 300, 300, 4, 6);
	// Game loop
	while (app.isOpen()) {
		while (app.pollEvent(e)) if(e.type==sf::Event::Closed) app.close();
		// Screen setup
		app.clear();
		ball1.action();
		ball2.action();
		app.display();
	}
	return EXIT_SUCCESS;
}

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
