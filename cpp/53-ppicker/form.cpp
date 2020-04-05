#include <iostream>
#include "functions.h"
#include "mustache.hpp"
#include "form.h"
void Form::addcoords(kainjow::mustache::data& coordset, float x, float y){
	kainjow::mustache::data pair;
	pair.set("x", std::to_string(x));
	pair.set("y", std::to_string(y));
	coordset<<kainjow::mustache::data{pair};
}
void Form::addxy(float x, float y){ addcoords(coordxy, x, y); }
void Form::addll(float x, float y){ addcoords(coordll, x, y); }
void Form::render(){
	data.set("rows", "19");
	data.set("coordxy", coordxy);
	data.set("coordll", coordll);
	kainjow::mustache::mustache tpl{readFile("points.tpl")};
 	std::cerr<<tpl.render(data)<<std::endl;
}
