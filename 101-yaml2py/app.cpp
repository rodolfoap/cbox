#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

class ConfDealer{
private:
	std::string filename;
	YAML::Node yaml;
public:
	ConfDealer(std::string f): filename(f) {
		yaml=YAML::LoadFile(filename);
	}
	void set(std::string key, std::string value){
		yaml[key]=value;
	}
	const std::string get(std::string key){
		return yaml[key].as<std::string>();
	}
	void save(){
		std::ofstream fout(filename);
		fout << yaml;
	}
};

std::string get(std::string filename, std::string key) {
	ConfDealer config(filename);
	return config.get(key);
}

void set(std::string filename, std::string key, std::string value) {
	ConfDealer config(filename);
	config.set(key, value);
	config.save();
}

int main() {
	// Simple setter and setter mechanism
	std::cout<<get("config.yaml", "password")<<std::endl;
	set("config.yaml", "password", "pipopi");
	std::cout<<get("config.yaml", "password")<<std::endl;

	// O-Oriented setter and setter mechanism
	ConfDealer config("config.yaml");
	std::cout<<config.get("password")<<std::endl;
	config.set("password", "qiqoqi");
	std::cout<<config.get("password")<<std::endl;
	config.save();
	return 0;
}
