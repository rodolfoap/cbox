#include <SFML/Graphics.hpp>

struct Window: public sf::RenderWindow {
	std::vector<sf::Vector2f> dots;
	sf::CircleShape dot;
	sf::Texture texture;
	sf::Sprite background;
	Window(const int, const int, const std::string, const char*);
	void drawBackground();
	void addDot(sf::Vector2i);
	void removeDot();
	void drawDots();
};
