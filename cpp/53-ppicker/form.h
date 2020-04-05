#include "mustache.hpp"
class Form{
private:
	kainjow::mustache::data data;
	kainjow::mustache::data coordxy;
	kainjow::mustache::data coordll;
	void addcoords(kainjow::mustache::data& coordset, float x, float y);
public:
	Form(): coordxy(kainjow::mustache::data::type::list), coordll(kainjow::mustache::data::type::list){}
	void addxy(float x, float y);
	void addll(float x, float y);
	void render();
};
