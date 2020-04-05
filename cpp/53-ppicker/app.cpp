#include <iostream>
#include "functions.h"
#include "window.h"
#include "form.h"

int main(int argc, char* argv[]) {
	Form form;
	sf::Event event;

	if(argc==1) { std::cerr<<"Usage: "<<argv[0]<<" [IMAGE_FILE]" <<std::endl; return 0; }
	std::string points=readFile("points.dat");

	Window window(800, 600, "PPicker", argv[1]);

	// Loop
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
