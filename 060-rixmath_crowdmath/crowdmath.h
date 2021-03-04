// Based on Stefan Woskowiak(www.rixcode.com) rixmath.h
#ifndef CROWDMATH_H_
#define CROWDMATH_H_

#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <math.h>

namespace cdm {
const float PI = 3.14159265358979f;
float RADTODEG(const float Radians) { return Radians * 180.0f / PI; }
float DEGTORAD(const float Degrees) { return Degrees * PI / 180.0f; }

// Length
template <class T>
float Length(const sf::Vector2<T> &vec) { return sqrt(vec.x * vec.x + vec.y * vec.y); }

// Normalize
template <class T>
void Normalize(sf::Vector2<T> &vec, float scale) {
	vec/=(Length(vec));
	vec*=scale;
}

// Normalize + Factory
template <class T>
sf::Vector2<T> Normalized(sf::Vector2<T> &vec, float scale) {
	sf::Vector2<T> result=vec;
	result/=(Length(result));
	result*=scale;
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

// Angle related to coords
template <class T>
float Angle(const sf::Vector2<T> &v1) {
	return atan2(v1.y, v1.x);
}
template <class T>
float AngleDeg(const sf::Vector2<T> &v1) {
	return RADTODEG(atan2(v1.y, v1.x));
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

// Closest Point in Line segment A-B
template <class T>
sf::Vector2<T> ClosestPointInLine(const sf::Vector2<T>& p, const sf::Vector2<T>& a, const sf::Vector2<T>& b) {
	sf::Vector2<T> vectorAP=p-a, vectorAB=b-a;
	float magAB=pow(Length(vectorAB), 2);
	float dotABAP=Dot(vectorAP, vectorAB);
	float distance=dotABAP/magAB;
	std::cerr<<"DISTANCE="<<distance<<std::endl;
	if     (distance<0) { return a; }
	else if(distance>1) { return b; }
	else return a+vectorAB*distance;
}

// Random
float random(float min, float max) {
	return (float)rand()/(RAND_MAX)*(max-min)+min;
}

} //namespace
#endif
