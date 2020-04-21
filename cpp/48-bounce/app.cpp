#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.cpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 30
sf::Event e;

int main() {
	// Open window
	sf::RenderWindow win(sf::VideoMode(800, 600), "SFML window", sf::Style::Titlebar|sf::Style::Close);
	win.setFramerateLimit(60);
	std::vector<Ball> balls(BALLS_QUANTITY, Ball(win));
	for(Ball& ball: balls) ball.setConfig(rand()%800+1, rand()%600+1, rand()%5-2, rand()%5-2);
	// Game loop
	while(win.isOpen()) {
		while (win.pollEvent(e)) if(e.type==sf::Event::Closed) win.close();
		win.clear();
		for(Ball& ball: balls) {
			ball.checkBorderColision();
			ball.update();
			win.draw(ball.getsprite());
		}
		win.display();
	}
	return EXIT_SUCCESS;
}
