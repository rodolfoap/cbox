#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
std::string readFile(std::string name){
	std::ifstream ifs(name, std::ios::binary);
	std::stringstream buffer;
	buffer<<ifs.rdbuf();
	ifs.close();
	return buffer.str();
}
