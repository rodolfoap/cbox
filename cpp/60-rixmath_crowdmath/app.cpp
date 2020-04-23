#include <iostream>
#include <SFML/Graphics.hpp>
#include "crowdmath.h"

#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

sf::Event event;
int main() {
	sf::Vector2f vector2=sf::Vector2f(10, 0);
	std::cerr<<"Vx="<<vector2.x<<std::endl;
	std::cerr<<"Vy="<<vector2.y<<std::endl;

	sf::Vector2f rotated=vector2;
	std::cerr<<"rot(0) Vx="<<rotated.x<<std::endl;
	std::cerr<<"rot(0) Vy="<<rotated.y<<std::endl;
	std::cerr<<"rot(0)  A="<<cdm::Angle(rotated)<<std::endl;
	cdm::Rotate(rotated, cdm::PI/2.0);
	std::cerr<<"rot(90) Vx="<<rotated.x<<std::endl;
	std::cerr<<"rot(90) Vy="<<rotated.y<<std::endl;
	std::cerr<<"rot(90)  A="<<cdm::Angle(rotated)<<std::endl;
	cdm::Rotate(rotated, cdm::PI/2.0);
	std::cerr<<"rot(180) Vx="<<rotated.x<<std::endl;
	std::cerr<<"rot(180) Vy="<<rotated.y<<std::endl;
	std::cerr<<"rot(180)  A="<<cdm::Angle(rotated)<<std::endl;
	cdm::Rotate(rotated, cdm::PI/2.0);
	std::cerr<<"rot(270) Vx="<<rotated.x<<std::endl;
	std::cerr<<"rot(270) Vy="<<rotated.y<<std::endl;
	std::cerr<<"rot(270)  A="<<cdm::Angle(rotated)<<std::endl;
	cdm::Rotate(rotated, -cdm::PI*1.50);
	std::cerr<<"rot(-270) Vx="<<rotated.x<<std::endl;
	std::cerr<<"rot(-270) Vy="<<rotated.y<<std::endl;
	std::cerr<<"rot(-270)  A="<<cdm::Angle(rotated)<<std::endl;

	float angle=cdm::Angle(rotated);

	float radius=cdm::Length(vector2);
	std::cerr<<"R="<<radius<<std::endl;

	sf::Vector2f norm=vector2;
	cdm::Normalize(norm, 1);
	radius=cdm::Length(norm);
	std::cerr<<"R="<<radius<<std::endl;

	sf::Vector2f P=sf::Vector2f( 5,  5);
	sf::Vector2f A=sf::Vector2f( 0, 10);
	sf::Vector2f B=sf::Vector2f(10,  5);
	sf::Vector2f cpil=cdm::ClosestPointInLine(P, A, B);
	std::cerr<<"Line   : ("<<   A.x<<", "<<   A.y<<"), ("<<B.x<<", "<<B.y<<"), "<<std::endl;
	std::cerr<<"Point  : ("<<   P.x<<", "<<   P.y<<")"<<std::endl;
	std::cerr<<"Closest: ("<<cpil.x<<", "<<cpil.y<<")"<<std::endl;

	return EXIT_SUCCESS;
}
