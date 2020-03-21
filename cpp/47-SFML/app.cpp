#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

sf::Event event;
int main() {
	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Background
	sf::Texture texture;
	if (!texture.loadFromFile("background.jpg")) return EXIT_FAILURE;
	sf::Sprite background(texture);

	// Text
	sf::Font font;
	if (!font.loadFromFile("sansation.ttf")) return EXIT_FAILURE;
	sf::Text text("Hello, World!", font, 20);
	text.setFillColor(sf::Color(0, 0, 96));

	// Music
	sf::Music music;
	if (!music.openFromFile("music.ogg")) return EXIT_FAILURE;

	// Play the music
	music.play();

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
			if(event.type==sf::Event::Resized){
				std::cerr<<"r";
				// This will resize the window internally, that is, more points woule be available
				// otherwise, the window gets bigger, but the contents remain the same.
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        			window.setView(sf::View(visibleArea));
				window.clear();
				window.draw(background);
				text.setString(	std::to_string(window.getSize().x)+":"+
						std::to_string(window.getSize().y)+"::"+
						std::to_string(sf::Mouse::getPosition(window).x)+":"+
						std::to_string(sf::Mouse::getPosition(window).y) );
				window.draw(text);
			}
			if(event.type==sf::Event::MouseButtonPressed){
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
