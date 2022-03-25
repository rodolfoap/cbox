#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

std::string get(std::string filename, std::string key) {
	YAML::Node config=YAML::LoadFile(filename);
	return config[key].as<std::string>();
}

void set(std::string filename, std::string key, std::string value) {
	YAML::Node config=YAML::LoadFile(filename);
	config[key]=value;
	std::ofstream fout(filename);
	fout << config;
}

int main() {
	std::cout<<"Password: "<<get("config.yaml", "password")<<std::endl;
	set("config.yaml", "password", "pipopi");
	return 0;
}
