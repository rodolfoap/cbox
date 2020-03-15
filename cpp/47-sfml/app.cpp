#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main() {
	// Open window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Background
	sf::Texture background;
	if (!background.loadFromFile("background.jpg")) return EXIT_FAILURE;
	sf::Sprite sprite(background);

	// Text
	sf::Font font;
	if (!font.loadFromFile("sansation.ttf")) return EXIT_FAILURE;
	sf::Text text("Hello, World!", font, 50);
	text.setFillColor(sf::Color(0, 0, 96));

	// Music
	sf::Music music;
	if (!music.openFromFile("music.ogg")) return EXIT_FAILURE;

	// Play the music
	music.play();
	// Start the game loop
	while (window.isOpen()) {
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Draw the string
		window.draw(text);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}
