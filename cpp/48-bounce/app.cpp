#include <iostream>
#include <exception>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.cpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 3
sf::Event e;

int main() {
	// Open window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar||sf::Style::Close);
	app.setFramerateLimit(60);
	// Create a model and copy on all slots of vector
	Ball ball(app);
	std::vector<Ball> balls(BALLS_QUANTITY, ball);
	for(Ball& ball: balls) ball.setConfig(rand()%800+1, rand()%600+1, rand()%5+1, rand()%5+1);
	// Game loop
	while(app.isOpen()) {
		while (app.pollEvent(e)) if(e.type==sf::Event::Closed) app.close();
		app.clear();
		for(Ball& ball: balls) ball.update();
		app.display();
	}
	return EXIT_SUCCESS;
}

