#include <iostream>
#include <exception>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

struct Ball: sf::Sprite {
	sf::Texture texture;
	float radius, minDistance;
	sf::Vector2f pos, speed;

	void init(int width, int height, sf::Texture& texture);
	void updatePos();
	void move();
};
