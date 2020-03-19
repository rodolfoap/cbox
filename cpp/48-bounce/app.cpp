#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
sf::Event e;

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

int main() {
	// Open window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar||sf::Style::Close);
	app.setFramerateLimit(60);

	// Background
	sf::Texture t1, t2;
	if (!t1.loadFromFile("background.jpg")) return EXIT_FAILURE;
	if (!t2.loadFromFile("ball.png")) return EXIT_FAILURE;
	sf::Sprite background(t1);
	sf::Sprite ball(t2);

	float dx=6, dy=5;
	float x=300, y=300;
	// Game loop
	while (app.isOpen()) {
		while (app.pollEvent(e)) if(e.type==sf::Event::Closed) app.close();
		x+=dx; y+=dy; if(x<0||x>790)dx=-dx; if(y<0||y>580)dy=-dy;
		ball.setPosition(x, y);

		// Screen setup
		app.clear();
		app.draw(background);
		app.draw(ball);
		app.display();
	}
	return EXIT_SUCCESS;
}
