#include<iostream>

class Lover{
public:
	std::string name;
	// The operator + is being redefined
	Lover operator+(const Lover &aLover);
	Lover operator++(int);
};

Lover Lover::operator+(const Lover &aLover){
	Lover lover;
	lover.name=this->name+"_loves_"+aLover.name;
	return lover;
}

Lover Lover::operator++(int n){
	Lover lover;
	lover.name=this->name+"_loveshimself_"+this->name;
	return lover;
}

int main(){
	Lover lover1, lover2, loverS;
	lover1.name="lover1";
	lover2.name="lover2";

	loverS=lover1+lover2;

	std::cerr << lover1.name << std::endl;
	std::cerr << lover2.name << std::endl;
	std::cerr << loverS.name << std::endl;
	loverS=loverS++;
	std::cerr << loverS.name << std::endl;
	return 0;
}
