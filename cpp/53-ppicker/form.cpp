#include <iostream>
#include <SFML/Graphics.hpp>
#include "functions.cpp"
#include "mustache.hpp"
#include "form.h"
Form::Form(char* pFile, char* tFile): 
	coorduv(kainjow::mustache::data::type::list),
	coordxy(kainjow::mustache::data::type::list),
	pFile(pFile), tFile(tFile) {
		coords=readPoints(pFile);
	}
void Form::adduv(int x, int y){
	kainjow::mustache::data pair;
	pair.set("x", std::to_string(x));
	pair.set("y", std::to_string(y));
	coorduv<<kainjow::mustache::data{pair};
}
void Form::addxy(float x, float y, std::string c){
	kainjow::mustache::data pair;
	pair.set("x", std::to_string(x));
	pair.set("y", std::to_string(y));
	pair.set("c", c);
	coordxy<<kainjow::mustache::data{pair};
}
bool Form::render(std::vector<sf::Vector2f> dots){
	if(coords.size()!=dots.size()) {
 		std::cerr<<"[ERROR] The number of provided("<<coords.size()<<") and expected points ("<<dots.size()<<") is different."<<std::endl;
		return false;
	}
	for(int i=0; i<coords.size(); i++) addxy(std::get<0>(coords[i]), std::get<1>(coords[i]), std::get<2>(coords[i]));
 	std::cerr<<dots.size()<<std::endl;
	for(int i=0; i<dots.size(); i++) adduv(dots[i].x, dots[i].y);
	data.set("rows", "19");
	data.set("coorduv", coorduv);
	data.set("coordxy", coordxy);
	kainjow::mustache::mustache tpl{readFile(tFile)};
 	std::cerr<<tpl.render(data)<<std::endl;
	return true;
}
std::string Form::getDescription(int i){
	return std::get<2>(coords[i]);
}
