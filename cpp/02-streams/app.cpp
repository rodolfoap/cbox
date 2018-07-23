#include<iostream>
#include<string>

namespace std {
	class Zero {
	public:
		std::string text;
		void mirror();
	};
}

int main(){
	std::Zero zero;
	std::cin  >> zero.text;
	std::cerr << zero.text << std::endl;
}

// All C++ standard library namespace declarations belong to std::...
// Syntax: a) namespace decl {}; b) namespace::decl; c) using namespace decl
