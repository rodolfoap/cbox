#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "crowdmath.h"
#include "ball.h"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 100
#define WIDTH 1278
#define HEIGHT 749

// Globals
sf::Event e;
sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Bouncing", sf::Style::Titlebar||sf::Style::Close);
sf::Texture texture;
Ball balls[BALLS_QUANTITY];

// Method: bouncing
void checkBallCollision(Ball& a, Ball& b) {
	sf::Vector2f segment=b.pos-a.pos;
	float segmentLen=cdm::Length(segment);
	// Collision!
	if(segmentLen<a.minDistance) {
		// Correct distance to avoid overlapping: move myself (and the other?)
		sf::Vector2f segmentDelta=cdm::Normalized(segment, a.minDistance-segmentLen);
		a.pos-=segmentDelta;
		// b.pos+=segmentDelta;
		// Rotate both speeds to emulate bouncing on a vertical wall
		float angle=cdm::Angle(segment);
		cdm::Rotate(a.speed, -angle);
		cdm::Rotate(b.speed, -angle);
		// Then, simply exchange horizontal speeds
		std::swap(b.speed.x, a.speed.x);
		// Rotate back to original coordinates
		cdm::Rotate(a.speed, angle);
		cdm::Rotate(b.speed, angle);
	}
}

// Classical
void checkBorderCollision(Ball& b){
	if(b.pos.x<b.radius)        { b.pos.x=b.radius;        b.speed.x=-b.speed.x; }
	if(b.pos.x>WIDTH -b.radius) { b.pos.x=WIDTH -b.radius; b.speed.x=-b.speed.x; }
	if(b.pos.y<b.radius)        { b.pos.y=b.radius;        b.speed.y=-b.speed.y; }
	if(b.pos.y>HEIGHT-b.radius) { b.pos.y=HEIGHT-b.radius; b.speed.y=-b.speed.y; }
}

// Main entry point
void update(){
	for(int a=0; a<BALLS_QUANTITY; a++){
		balls[a].updatePos();
		for(int b=a+1; b<BALLS_QUANTITY; b++) checkBallCollision(balls[a], balls[b]);
		checkBorderCollision(balls[a]);
		balls[a].move();
	}
}

int main() {
	srand(time(0));
	// Window
	win.setPosition(sf::Vector2i(0, 0));
	win.setFramerateLimit(60);
	texture.loadFromFile("ball24.png");
	for(int a=0; a<BALLS_QUANTITY; a++) balls[a].init(WIDTH, HEIGHT, texture);
	// Loop
	while(win.isOpen()) {
                // Close window or pressing Q
		while (win.pollEvent(e)) if(e.key.code==sf::Keyboard::Q||e.type==sf::Event::Closed) win.close();
		// Drawing
		win.clear();
		update();
		for(int a=0; a<BALLS_QUANTITY; a++) win.draw(balls[a]);
		win.display();
	}
	return EXIT_SUCCESS;
}
