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
	sf::Text text("Hello, World!", font, 50);
	text.setFillColor(sf::Color(0, 0, 96));

	// Music
	sf::Music music;
	if (!music.openFromFile("music.ogg")) return EXIT_FAILURE;

	// Play the music
	music.play();

	window.clear();
	window.draw(background);
	window.display();

	sf::CircleShape dot(2);
	dot.setFillColor(sf::Color(0, 0, 96));

	// Game loop
	while (window.isOpen()) {
		// Process events
		while (window.pollEvent(event));
		switch(event.type){
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.clear();
				window.draw(background);
				text.setString(	std::to_string(window.getSize().x)+":"+
						std::to_string(window.getSize().y)+"-"+
						std::to_string(sf::Mouse::getPosition(window).x)+":"+
						std::to_string(sf::Mouse::getPosition(window).y) );
				window.draw(text);
				window.display();
				break;
			case sf::Event::MouseButtonPressed:
				dot.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x,
						window.mapPixelToCoords(sf::Mouse::getPosition(window)).y);
				window.draw(dot);
				window.display();
				break;
		}
	}
	return EXIT_SUCCESS;
}
