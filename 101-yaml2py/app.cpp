#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"
#include <stdio.h>
#include <string.h>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

class ConfDealer{
private:
	char* filename=new char[1024];
	char* stresult=new char[1024];
public:
	YAML::Node yaml;
	ConfDealer(char* f): filename(f) {
		yaml=YAML::LoadFile(filename);
	}
	void set(char* key, char* value){
		yaml[std::string(key)]=value;
	}
	const char* get(char* key){
		strcpy(stresult, yaml[std::string(key)].as<std::string>().c_str());
		return stresult;
	}
	void save(){
		std::ofstream fout(filename);
		fout << yaml;
	}
};

char* get(char* filename, char* key) {
	ConfDealer config(filename);
	char* stresult=new char[1024];
	strcpy(stresult, config.get(key));
	return stresult;
}

void set(char* filename, char* key, char* value) {
	ConfDealer config(filename);
	config.set(key, value);
	config.save();
}

int main() {
	char filename[]="config.yaml";
	char key[]="password";
	char value[]="petalo";

	// Simple setter and setter mechanism
	std::cout<<get(filename, key)<<std::endl;
	set(filename, key, value);
	std::cout<<get(filename, key)<<std::endl;

	// O-Oriented setter and setter mechanism
	ConfDealer config(filename);

	std::cout<<config.get(key)<<std::endl;

	char value2[]="sesamo";
	config.set(key, value2);
	config.save();
	std::cout<<config.get(key)<<std::endl;
	return 0;
}
