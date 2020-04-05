#include <iostream>
#include <fstream>
#include <tuple>
#include "window.h"
#include "form.h"

std::vector<std::tuple<float, float, std::string>> readPoints(std::string name){
	std::vector<std::tuple<float, float, std::string>> coords;
	float a, b; std::string c;
	std::ifstream ifs(name, std::ios::binary);
	while(ifs>>a>>b>>c) coords.push_back(make_tuple(a, b, c));
	ifs.close();
	return coords;
}
int main(int argc, char* argv[]) {
	Form form;
	sf::Event event;

	if(argc==1) { std::cerr<<"Usage: "<<argv[0]<<" [IMAGE_FILE]" <<std::endl; return 0; }
	std::vector<std::tuple<float, float, std::string>> coords=readPoints("points.dat");
	for(int i=0; i<coords.size(); i++) form.addll(std::get<0>(coords[i]), std::get<1>(coords[i]));

	Window window(800, 600, "PPicker", argv[1]);
	// Loop
	while (window.isOpen()) {
		// Process events: waitEvent() is blocking, pollEvent() is not.
		while (window.waitEvent(event)) {
			if(event.type==sf::Event::Resized) { window.clear(); }
			if(event.type==sf::Event::MouseButtonPressed) {
				// Left click is adding point
				if (event.mouseButton.button==sf::Mouse::Left) { window.addDot(sf::Mouse::getPosition(window)); }
				// Right click is removing last point
				if(event.mouseButton.button==sf::Mouse::Right) { window.removeDot(); }
			}
			// Close window or pressing Q
			if((event.key.code==sf::Keyboard::Q)||(event.type==sf::Event::Closed)) {
				form.render(window.dots);
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
