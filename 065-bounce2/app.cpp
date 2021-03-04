#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "crowdmath.h"
#include "ball.h"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define BALLS_QUANTITY 100
#define WIDTH 1278
#define HEIGHT 749
#define SOCIAL_DISTANCE 5
#define SOCIAL_INFLUENCE 2

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
	if(segmentLen<a.radius*2) {
		// Correct distance to avoid overlapping: move myself (and the other?)
		sf::Vector2f segmentDelta=cdm::Normalized(segment, a.radius*2-segmentLen);
		a.pos-=segmentDelta;
		b.pos+=segmentDelta;
	}
	// Social forces
	if(segmentLen<a.radius*2*SOCIAL_DISTANCE) {
		float intensity=pow(1-segmentLen/(a.radius*2*SOCIAL_DISTANCE), 2);
		sf::Vector2f segmentDelta=cdm::Normalized(segment, intensity*(1+SOCIAL_INFLUENCE));
		a.pos-=segmentDelta;
		b.pos+=segmentDelta;
	}
}

// Classical
void checkBorderCollision(Ball& b){
	if(b.pos.x<0)      { b.pos.x=0;      b.speed.x=-b.speed.x; }
	if(b.pos.x>WIDTH)  { b.pos.x=WIDTH;  b.speed.x=-b.speed.x; }
	if(b.pos.y<0)      { b.pos.y=0;      b.speed.y=-b.speed.y; }
	if(b.pos.y>HEIGHT) { b.pos.y=HEIGHT; b.speed.y=-b.speed.y; }

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
