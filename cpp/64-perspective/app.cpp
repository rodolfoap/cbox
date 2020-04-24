#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"homog2d.hpp"
sf::Event e;
class Perspective{
public:
	// d: Focal distance, recommended 1
	// z: Camera altitude from the ground
	// shiftH, shiftV: display shift
	// multH, multV: multipliers
	int d=1, z, shiftH, shiftV, multH, multV;
	homog2d::Homogr h;

	Perspective(int z, int shiftH, int shiftV, int multH, int multV):
		z(z), shiftH(shiftH), shiftV(shiftV), multH(multH), multV(multV) { }

	sf::Vector2f transformUV(double& a, double& b){
		h.setRotation(3.14/1.8); // 30deg
		h.addTranslation(0, 0);
		homog2d::Point2d p1(a, b);
		homog2d::Point2d p2 = h * p1;
		double x=p2.getX();
		double y=p2.getY();
		double u=x * d/(y+400) * multH + shiftH;
		double v=z * d/(y+400) * multV + shiftV;
		h.clear();
		return sf::Vector2f(u, v);
	}
};

int main() {
	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Dot
	sf::CircleShape red(1); red.setFillColor(sf::Color(255, 000, 000));
	sf::CircleShape grn(1); grn.setFillColor(sf::Color(000, 255, 000));
	// Values: (ground_alt, shiftH, shiftV, multH, multV);
	Perspective per( 20, 		// Ground altitude
			400,   -50,	// shift
			600,  2000);	// multipliers
	while (window.isOpen()) {
		while (window.pollEvent(e)) if(e.key.code==sf::Keyboard::Q||e.type==sf::Event::Closed) window.close();
		window.clear();
		for(double x=-400; x<400; x+=20) for(double y=-300; y<300; y+=20) {
			red.setPosition(x+400, y+300);          window.draw(red);
			grn.setPosition(per.transformUV(x, y)); window.draw(grn);
		}
		window.display();
	}
	return EXIT_SUCCESS;
}
