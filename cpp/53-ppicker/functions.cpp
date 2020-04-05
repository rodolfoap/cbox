#include <fstream>
#include <sstream>
#include <iostream>
std::string readFile(std::string name){
	std::ifstream ifs(name, std::ios::binary);
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	ifs.close();
	return buffer.str();
}
