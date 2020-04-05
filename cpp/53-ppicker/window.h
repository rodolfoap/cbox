#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct Window: public sf::RenderWindow {
	std::vector<sf::Vector2f> dots;
	sf::CircleShape dot;
	sf::Texture texture;
	sf::Sprite background;
	Window(const int width, const int height, const std::string title, const char* bgndfile);
	void drawBackground();
	void addDot(const sf::Vector2f dot);
	void removeDot();
	void drawDots();
};
