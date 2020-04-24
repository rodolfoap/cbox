#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define SHIFT_U +400
#define SHIFT_V -150
#define MULTI_U 800
#define MULTI_V 10000
sf::Event e;
int main() {
	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Dot
	sf::CircleShape red(1); red.setFillColor(sf::Color(255,   0, 0));
	sf::CircleShape grn(1); grn.setFillColor(sf::Color(   0,255, 0));
	// Game loop
	while (window.isOpen()) {
		while (window.pollEvent(e)) if(e.key.code==sf::Keyboard::Q||e.type==sf::Event::Closed) window.close();
		window.clear();
		int d=1;
		int z=20;
		for(double x=-400; x<400; x+=20) for(double y=-300; y<300; y+=20) {
			red.setPosition(x+400, y+300); window.draw(red);
			double u=x * d/(y+600) *MULTI_U + SHIFT_U;
			double v=z * d/(y+600) *MULTI_V + SHIFT_V;
			grn.setPosition(u, v); window.draw(grn);
		}
		window.display();
	}
	return EXIT_SUCCESS;
}
