#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.cpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 30
#define WIDTH 800
#define HEIGHT 600
sf::Event e;

int main() {
	// Window
	sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "SFML window", sf::Style::Titlebar|sf::Style::Close);
	win.setFramerateLimit(60);
	std::vector<Ball> balls(BALLS_QUANTITY, Ball(win, WIDTH, HEIGHT));
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
