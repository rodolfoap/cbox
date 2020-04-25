#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.cpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 10
#define WIDTH 1278
#define HEIGHT 748
sf::Event e;

int main() {
	// Window
	sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "SFML window", sf::Style::Titlebar|sf::Style::Close);
	win.setPosition(sf::Vector2i(0, 0));
	win.setFramerateLimit(60);
	std::vector<Ball> balls(BALLS_QUANTITY, Ball(win, WIDTH, HEIGHT));

	// Loop
	srand(time(0));
	while(win.isOpen()) {
                // Close window or pressing Q
		while (win.pollEvent(e)) if(e.key.code==sf::Keyboard::Q||e.type==sf::Event::Closed) win.close();
		// Drawing
		win.clear();
		for (std::vector<Ball>::iterator ball=balls.begin(); ball!=balls.end(); ++ball) {
			ball->update();
			// Double loop for interactions: 1-2, 1-3, 1-4, 2-3, 2-4, 3-4 (if 4 objects)
			for (std::vector<Ball>::iterator ball2=ball+1; ball2!=balls.end(); ++ball2) ball->checkBallColision(*ball2);
			ball->checkBorderColision();
			ball->move();
			win.draw(ball->sprite);
		}
		win.display();
	}
	return EXIT_SUCCESS;
}
