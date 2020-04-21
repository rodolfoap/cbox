//Author: Stefan Woskowiak, www.rixcode.com
#ifndef SFMATH_H_
#define SFMATH_H_

//include only the headers we need
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <iostream>
#include <limits>
#include <math.h>

const float PI = 3.14159265358979f;
float RADTODEG(const float Radians) { return Radians * 180.0f / PI; }
float DEGTORAD(const float Degrees) { return Degrees * PI / 180.0f; }

namespace sfm {
//Zero out
template <class T>
void Zero(sf::Vector3<T> &vec) { vec.x = vec.y = vec.z = 0; }
template <class T>
void Zero(sf::Vector2<T> &vec) { vec.x = vec.y = 0; }

//Negation
template <class T>
void Negate(sf::Vector3<T> &vec) { vec.x = -vec.x; vec.y = -vec.y; vec.z = -vec.z; }
template <class T>
void Negate(sf::Vector2<T> &vec) { vec.x = -vec.x; vec.y = -vec.y; }

// Length
template <class T>
float Length(const sf::Vector3<T> &vec) { return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z); }
template <class T>
float Length(const sf::Vector2<T> &vec) { return sqrt(vec.x * vec.x + vec.y * vec.y); }

// Normalize
template <class T>
void Normalize(sf::Vector3<T> &vec) { float len = Length(vec); vec/=(len); }
template <class T>
void Normalize(sf::Vector2<T> &vec) { float len = Length(vec); vec/=(len); }

// DOT product
template <class T>
float Dot(const sf::Vector3<T> &v1, const sf::Vector3<T> &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
template <class T>
float Dot(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return v1.x * v2.x + v1.y * v2.y; }

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
float Angle(const sf::Vector3<T> &v1, const sf::Vector3<T> &v2) {
	float len1 = Length(v1);
	float len2 = Length(v2);
	if (len1==0 || len2==0) return 0;
	float angle = acosf(Dot(v1, v2) / (len1 * len2));
	if (std::numeric_limits<float>(angle)) return 0;
	return angle;
}
template <class T>
float Angle(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return acos(Dot(v1, v2));
}
template <class T>
float Angle(const sf::Vector2<T> &v1) {
	return atan2(v1.y, v1.x);
}

//Calculate angle between two vectors and returns it in degrees.
template <class T>
float AngleBetweenD(const sf::Vector3<T> &v1, const sf::Vector3<T> &v2) {
	return RADTODEG(AngleBetweenR(v1, v2));
}

template <class T>
float AngleBetweenD(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return RADTODEG(AngleBetweenR(v1, v2));
}

//Calculate the cross product of two 3D vectors
template <class T>
sf::Vector3<T> Cross(const sf::Vector3<T> &v1, const sf::Vector3<T> &v2) {
	sf::Vector3<T> vResult;
	vResult.x = v1.y * v2.z - v1.z * v2.y;
	vResult.y = v1.z * v2.x - v1.x * v2.z;
	vResult.z = v1.x * v2.y - v1.y * v2.x;
	return vResult;
}

template <class T>
float Cross(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	return((v1.x * v2.y) - ( v1.y * v2.x ));
}

//Distance between two points
template <class T>
float Distance(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) {
	float x = v2.x - v1.x;
	float y = v2.y - v1.y;
	return sqrt(x*x + y*y);
}

//Convert a 2D vector to a 3D vector ( nothing fancy just for a time saver )
template <class T>
sf::Vector3<T> Convert2Dto3D(const sf::Vector2<T> &vec) { return sf::Vector3<T>(vec.x, vec.y, 0); }
}// namespace sfMath

#endif
