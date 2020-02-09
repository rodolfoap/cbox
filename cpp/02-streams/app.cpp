#include<iostream>
#include<string>

class Zero{
public:
	std::string text;
};

int main(){
	Zero zero;
	std::cerr << "Text: ";
	std::cin  >> zero.text;
	std::cerr << "Text, obtained from the object: " << zero.text << std::endl;
}

// All C++ standard library namespace declarations belong to std::...
// Syntax: a) namespace decl {}; b) namespace::decl; c) using namespace decl
