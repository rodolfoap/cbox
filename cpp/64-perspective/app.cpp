#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
sf::Event e;
class Perspective{
public:
	// d: Focal distance, recommended 1;
	// z: Camera altitude from the ground
	// shiftH, shiftV: display shift
	// multH, multV: multipliers
	int d=1, z, shiftH, shiftV, multH, multV;

	Perspective(int z, int shiftH, int shiftV, int multH, int multV):
		z(z), shiftH(shiftH), shiftV(shiftV), multH(multH), multV(multV) {}

	sf::Vector2f transformUV(double& x, double& y){
		return sf::Vector2f(
			x * d/(y+600) * multH + shiftH ,
			z * d/(y+600) * multV + shiftV
		);
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
			400,  -150,	// shift
			400, 10000);	// multipliers
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
