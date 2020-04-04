#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

sf::Event event;
int main(int argc, char* argv[]) {
	if(argc==1) { std::cerr<<"Usage: "<<argv[0]<<" [IMAGE_FILE]" <<std::endl; return 0; }

	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "PPicker");

	// Background
	sf::Texture texture;
	if (!texture.loadFromFile(argv[1])) return EXIT_FAILURE;
	sf::Sprite background(texture);

	// Dot
	sf::CircleShape dot(20);
	dot.setFillColor(sf::Color(0, 96, 96));

	// Screen setup
	window.clear();
	window.draw(background);
	window.display();

	// Game loop
	while (window.isOpen()) {
		// Process events: waitEvent() is blocking, pollEvent() is not.
		while (window.waitEvent(event)){
			window.draw(background);
			if(event.type==sf::Event::Resized){
				std::cerr<<"r";
				window.clear();
			}
			if(event.type==sf::Event::MouseButtonReleased){
				std::cerr<<".";
				dot.setPosition(sf::Mouse::getPosition(window).x-20,
						sf::Mouse::getPosition(window).y-20);
				window.draw(dot);
			}
			if(event.type==sf::Event::Closed){ std::cerr<<"c\n"; window.close(); }
			window.display();
		}
	}
	return EXIT_SUCCESS;
}
