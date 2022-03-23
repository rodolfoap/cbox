#include <iostream>
#include "yaml-cpp/yaml.h"
#define LOG std::cerr<<">>>"<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main() {
	YAML::Emitter yaml;
	yaml<<"Hello, World!";

	// Printing yaml to stdout
	std::cout << yaml.c_str() << std::endl;

	return 0;
}
