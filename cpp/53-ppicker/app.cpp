#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "mustache.hpp"
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define RADIUS 4

std::string readFile(std::string name){
	std::ifstream ifs(name, std::ios::binary);
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	ifs.close();
	return buffer.str();
}
class Form{
private:
	kainjow::mustache::data data;
	kainjow::mustache::data coordxy;
	kainjow::mustache::data coordll;
	void addcoords(kainjow::mustache::data& coordset, float x, float y){
		kainjow::mustache::data pair;
		pair.set("x", std::to_string(x));
		pair.set("y", std::to_string(y));
		coordset<<kainjow::mustache::data{pair};
	}
public:
	Form(): coordxy(kainjow::mustache::data::type::list), coordll(kainjow::mustache::data::type::list){}
	void addxy(float x, float y){ addcoords(coordxy, x, y); }
	void addll(float x, float y){ addcoords(coordll, x, y); }
	void render(){
		data.set("rows", "19");
		data.set("coordxy", coordxy);
		data.set("coordll", coordll);
		kainjow::mustache::mustache tpl{readFile("points.tpl")};
 		std::cerr<<tpl.render(data)<<std::endl;
	}
};

int main(int argc, char* argv[]) {
	Form form;
	sf::Event event;
	std::vector<sf::Vector2f> dots;

	if(argc==1) { std::cerr<<"Usage: "<<argv[0]<<" [IMAGE_FILE]" <<std::endl; return 0; }
	std::string points=readFile("points.dat");

	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "PPicker");
	// Background
	sf::Texture texture;
	if (!texture.loadFromFile(argv[1])) return EXIT_FAILURE;
	sf::Sprite background(texture);
	// Dot
	sf::CircleShape dot(RADIUS);
	dot.setFillColor(sf::Color(255, 0, 0));
	// Screen setup
	window.clear();
	window.draw(background);
	window.display();
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
					dots.push_back(worldPos);
				}
				// Right click is removing last point
				if(event.mouseButton.button==sf::Mouse::Right) { if(dots.size()>0) dots.pop_back(); }
			}
			// Close window or pressing Q
			if((event.key.code==sf::Keyboard::Q)||(event.type==sf::Event::Closed)) {
				for(int i=0; i<dots.size(); i++) form.addxy(dots[i].x, dots[i].y);
				form.render();
				window.close();
			}

			// Drawing
			window.draw(background);
			for(int i=0; i<dots.size(); i++) {
				dot.setPosition(dots[i].x-RADIUS-1, dots[i].y-RADIUS-1);
				window.draw(dot);
			}
			window.display();
		}
	}
	return EXIT_SUCCESS;
}
