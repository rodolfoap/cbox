#include<iostream>
#include<string>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

class ZeroClass{
// Private by default
public:
	std::string text;
};

struct ZeroStruct{
// Public by default
	std::string text;
};

int main(){
	ZeroClass zero;
	ZeroStruct one;
	std::cerr << "Text: ";
	std::cin  >> zero.text;
	one.text=zero.text;
	std::cerr << "Text, obtained from the object: " << zero.text << std::endl;
	std::cerr << "Text, obtained from the struct: " <<  one.text << std::endl;
}

// All C++ standard library namespace declarations belong to std::...
// Syntax: a) namespace decl {}; b) namespace::decl; c) using namespace decl
