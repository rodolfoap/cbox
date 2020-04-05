#include <SFML/Graphics.hpp>
#include "functions.h"
#include "window.h"
#define RADIUS 4

Window::Window(const int width, const int height, const std::string title, const char* bgndfile):
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
void Window::drawBackground(){
	this->clear();
	this->draw(background);
};
void Window::addDot(const sf::Vector2f dot){
	dots.push_back(dot);
}
void Window::removeDot(){
	if(dots.size()>0) dots.pop_back();
}
void Window::drawDots(){
	for(int i=0; i<dots.size(); i++) {
		dot.setPosition(dots[i].x-RADIUS-1, dots[i].y-RADIUS-1);
		this->draw(dot);
	}
}
