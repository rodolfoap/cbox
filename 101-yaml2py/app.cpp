#include <iostream>
#include "yaml-cpp/yaml.h"
#define LOG std::cerr<<">>>"<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#include <fstream>

int main() {
//	YAML::Emitter yaml;
//	yaml<<"Hello, World!";

	// Printing yaml to stdout
//	std::cout << yaml.c_str() << std::endl;

	YAML::Node config = YAML::LoadFile("config.yaml");

	if(config["lastLogin"]){ std::cout << "Last logged in: " << config["lastLogin"].as<std::string>() << "\n"; }
	const std::string username = config["username"].as<std::string>();
	const std::string password = config["password"].as<std::string>();
	//login(username, password);
	config["lastLogin"] = "10/10/2020";

	std::ofstream fout("config.yaml");
	fout << config;
	return 0;
}
