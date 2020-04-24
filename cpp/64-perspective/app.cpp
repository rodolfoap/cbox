#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define SHIFT_U +10
#define SHIFT_V -500
#define MULTI_U 800
#define MULTI_V 20000
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
		int z=40;
		for(double x=0; x<800; x+=20) for(double y=0; y<600; y+=20) {
			red.setPosition(x, y); window.draw(red);
			double u=x * d/(y+800) *MULTI_U + SHIFT_U;
			double v=z * d/(y+800) *MULTI_V + SHIFT_V;
			grn.setPosition(u, v); window.draw(grn);
		}
		window.display();
	}
	return EXIT_SUCCESS;
}
