#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ball.cpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 100
#define WIDTH 1278
#define HEIGHT 749
sf::Event e;

int main() {
	// Window
	sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Bouncing", sf::Style::Titlebar||sf::Style::Close);
	win.setPosition(sf::Vector2i(0, 0));
	win.setFramerateLimit(60);
	Ball balls[BALLS_QUANTITY];
	for(int a=0; a<BALLS_QUANTITY; a++){ balls[a].init(WIDTH, HEIGHT); }

	// Loop
	srand(time(0));
	while(win.isOpen()) {
                // Close window or pressing Q
		while (win.pollEvent(e)) if(e.key.code==sf::Keyboard::Q||e.type==sf::Event::Closed) win.close();
		// Drawing
		win.clear();
		for(int a=0; a<BALLS_QUANTITY; a++){ 
			balls[a].update();
			// Double loop for interactions: 1-2, 1-3, 1-4, 2-3, 2-4, 3-4 (if 4 objects)
			for(int b=a+1; b<BALLS_QUANTITY; b++) balls[a].checkBallColision(balls[b]);
			balls[a].checkBorderColision();
			balls[a].move();
			win.draw(balls[a].sprite);
		}
		win.display();
	}
	return EXIT_SUCCESS;
}
