#include <secbroker.hpp>

void SecBroker::print(std::string label){
	std::cerr<<label<<"::print(): "<<name<<"/"<<width<<std::endl;
}
