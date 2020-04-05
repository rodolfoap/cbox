#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define RADIUS 4

sf::Event event;
int main(int argc, char* argv[]) {
	std::vector<sf::Vector2f> dots;
	if(argc==1) { std::cerr<<"Usage: "<<argv[0]<<" [IMAGE_FILE]" <<std::endl; return 0; }
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
				for(int i=0; i<dots.size(); i++) { std::cerr<<dots[i].x<<":"<<dots[i].y<<std::endl; }
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
