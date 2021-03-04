//Based on Stefan Woskowiak(www.rixcode.com) rixmath.h
#ifndef SFMATH_H_
#define SFMATH_H_

//include only the headers we need
#include <SFML/System/Vector2.hpp>
#include <limits>
#include <math.h>

const float PI = 3.14159265358979f;
float RADTODEG(const float Radians) { return Radians * 180.0f / PI; }
float DEGTORAD(const float Degrees) { return Degrees * PI / 180.0f; }

namespace sfm {
//Zero out
template <class T>
void Zero(sf::Vector2<T> &vec) { vec.x = vec.y = 0; }

//Negation
template <class T>
void Negate(sf::Vector2<T> &vec) { vec.x = -vec.x; vec.y = -vec.y; }

// Length
template <class T>
float Length(const sf::Vector2<T> &vec) { return sqrt(vec.x * vec.x + vec.y * vec.y); }

// Normalize
template <class T>
void Normalize(sf::Vector2<T> &vec) { float len = Length(vec); vec/=(len); }
template <class T>
sf::Vector2<T> Normalized(sf::Vector2<T> &vec) {
	sf::Vector2<T> result=vec;
	result/=(Length(result));
	return result;
}

// DOT product
template <class T>
float Dot(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

// Rotate vector2 (2D only)
template <class T>
void Rotate(sf::Vector2<T> &vec, float angle) {
	float sin1 = sin(angle);
	float cos1 = cos(angle);
	float tempx = (vec.x * cos1) - (vec.y * sin1);
	vec.y = (vec.y * cos1) + (vec.x * sin1);
	vec.x = tempx;
}

// Angle
template <class T>
float Angle(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return acos(Dot(v1, v2));
}
template <class T>
float Angle(const sf::Vector2<T> &v1) {
	return atan2(v1.y, v1.x);
}

// Calculate the cross product of two vectors
template <class T>
float Cross(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return((v1.x * v2.y) - ( v1.y * v2.x ));
}

// Distance between two points
template <class T>
float Distance(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	float x = v2.x - v1.x;
	float y = v2.y - v1.y;
	return sqrt(x*x + y*y);
}

// Random
float random(float min, float max){
	return (float)rand()/(RAND_MAX)*(max-min)+min;
}

}// namespace sfMath
#endif
