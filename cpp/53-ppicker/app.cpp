#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "functions.h"
#include "form.h"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define RADIUS 4

struct Window: public sf::RenderWindow {
	std::vector<sf::Vector2f> dots;
	sf::CircleShape dot;
	sf::Texture texture;
	sf::Sprite background;
	Window(const int width, const int height, const std::string title, const char* bgndfile):
		sf::RenderWindow(sf::VideoMode(width, height), title), dot(RADIUS) {

		// Background
		texture.loadFromFile(bgndfile);
		background.setTexture(texture);
		// Dot
		dot.setFillColor(sf::Color(255, 0, 0));
		// Screen setup
		this->clear();
		this->draw(background);
		this->display();
	}
	void drawBackground(){
		this->clear();
		this->draw(background);
	};
	void addDot(const sf::Vector2f dot){
		dots.push_back(dot);
	}
	void removeDot(){
		if(dots.size()>0) dots.pop_back();
	}
	void drawDots(){
		for(int i=0; i<dots.size(); i++) {
			dot.setPosition(dots[i].x-RADIUS-1, dots[i].y-RADIUS-1);
			this->draw(dot);
		}
	}
};

int main(int argc, char* argv[]) {
	Form form;
	sf::Event event;

	if(argc==1) { std::cerr<<"Usage: "<<argv[0]<<" [IMAGE_FILE]" <<std::endl; return 0; }
	std::string points=readFile("points.dat");

	// Open window
	Window window(800, 600, "PPicker", argv[1]);

	// Game loop
	while (window.isOpen()) {
		// Process events: waitEvent() is blocking, pollEvent() is not.
		while (window.waitEvent(event)) {
			if(event.type==sf::Event::Resized) { window.clear(); }
			if(event.type==sf::Event::MouseButtonPressed) {
				// Left click is adding point
				if (event.mouseButton.button==sf::Mouse::Left) {
					// See https://www.sfml-dev.org/tutorials/2.0/graphics-view.php#showing-more-when-the-window-is-resized
					sf::Vector2i pixelPos=sf::Mouse::getPosition(window);
					sf::Vector2f worldPos=window.mapPixelToCoords(pixelPos);
					window.addDot(worldPos);
				}
				// Right click is removing last point
				if(event.mouseButton.button==sf::Mouse::Right) { window.removeDot(); }
			}
			// Close window or pressing Q
			if((event.key.code==sf::Keyboard::Q)||(event.type==sf::Event::Closed)) {
				for(int i=0; i<window.dots.size(); i++) form.addxy(window.dots[i].x, window.dots[i].y);
				form.render();
				window.close();
			}

			// Drawing
			window.drawBackground();
			window.drawDots();
			window.display();
		}
	}
	return EXIT_SUCCESS;
}
