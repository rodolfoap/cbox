#include<iostream>
#include<string>

struct Entity {
	int age;
	std::string name;

	Entity(){};

	// Implicit constructor
	Entity(const std::string& a_name) 	: age(11), name(a_name) {};

	// Explicit constructor
	explicit Entity(int an_age)			: age(an_age), name("noname")  {};
};

int main(){
	// Implicit: this calls the constructor Entity(int)
	Entity g=std::string("john");
	std::cerr<<g.age<<":"<<g.name<<std::endl;

	// Explicit: cannot be called as this:
	// Entity e=13;
	// Only as this:
	Entity e(13);

	std::cerr<<e.age<<":"<<e.name<<std::endl;
	return 0;
}
