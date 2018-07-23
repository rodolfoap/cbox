#include<iostream>
#include<string>
class Thing{
public:
	std::string name;
};
class Concept :public Thing{
public:
	void setName(std::string);
	std::string getName();
};
void Concept::setName(std::string aName){
	name=aName;
}
std::string Concept::getName(){
	return name;
}
int main(){
	Concept concept;
	concept.setName("yoyo");
	std::cout << concept.getName() << std::endl;
	return 0;
}
