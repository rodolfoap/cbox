#include "homog2d.hpp"

int main() {
	// a line passing through (0,0) and (10,10)
	h2d::Line2d l1(h2d::Point2d(10,10) );

	// a line passing through (0,10) and (10,0)
	h2d::Line2d l2(h2d::Point2d( 0,10), h2d::Point2d(10, 0) );

	// intersection point (5,5)
	auto pt = h2d::operator*(l1, l2);

	// a translation matrix
	h2d::Homogr H(2,3);
	
	std::cout << H * pt; // prints [7,8]
}

