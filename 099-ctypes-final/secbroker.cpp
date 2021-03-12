#include <iostream>
#include <cstring>
#include <holder.hpp>
#include <secbroker.hpp>

void secbroker::print(std::string label){
	std::cerr<<label<<"::print(): "<<name<<"/"<<width<<std::endl;
}
