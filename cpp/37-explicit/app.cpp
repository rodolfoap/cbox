#include<iostream>
#include<string.h>

class Entity{
private:
	int age;
public:
	Entity(){};
	Entity(int an_age){ age=an_age; };
	int getAge(){ return age; }
};

int main(){
	// Implicit: this calls the constructor Entity(int)
	Entity e=13;
	std::cerr<<e.getAge()<<std::endl;
	return 0;
}
