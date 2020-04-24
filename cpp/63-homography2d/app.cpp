#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"homog2d.hpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define SHIFT_X 200
#define SHIFT_Y 200

sf::Event e;
int main() {
	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Dot
	sf::CircleShape red(2); red.setFillColor(sf::Color(255,   0, 0));
	sf::CircleShape grn(2); grn.setFillColor(sf::Color(   0,255, 0));
	homog2d::Homogr h;
	// Game loop
	while (window.isOpen()) {
		while (window.pollEvent(e)) if(e.key.code==sf::Keyboard::Q||e.type==sf::Event::Closed) window.close();
		window.clear();
		for(float x=0; x<200; x+=20) for(float y=0; y<200; y+=20) {
			red.setPosition(x+SHIFT_X, y+SHIFT_Y); window.draw(red);
			h.setRotation(3.14/6.0); // 30deg
			h.addTranslation(40, 0);
			homog2d::Point2d pt1(x,y);
			homog2d::Point2d pt2 = h * pt1;
			h.clear();
			grn.setPosition(pt2.getX()+SHIFT_X, pt2.getY()+SHIFT_Y); window.draw(grn);
		}
		window.display();
	}
	return EXIT_SUCCESS;
}
