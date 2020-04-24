#include <SFML/Graphics.hpp>
#include "homog2d.hpp"
class Perspective{
public:
	// d: Focal distance, recommended 1
	// z: Camera altitude from the ground
	// shiftH, shiftV: display shift
	// multH, multV: multipliers
	int d=1, z, shiftH, shiftV, multH, multV;
	homog2d::Homogr h;

	Perspective(int z, int shiftH, int shiftV, int multH, int multV):
		z(z), shiftH(shiftH), shiftV(shiftV), multH(multH), multV(multV) { }

	sf::Vector2f transformUV(double& a, double& b){
		h.setRotation(100*3.1416/180);
		h.addTranslation(0, 0);
		homog2d::Point2d p1(a, b);
		homog2d::Point2d p2 = h * p1;
		double x=p2.getX();
		double y=p2.getY();
		double u=x * d/(y+800) * multH + shiftH;
		double v=z * d/(y+800) * multV + shiftV;
		h.clear();
		return sf::Vector2f(u, v);
	}
};
