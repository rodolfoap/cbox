#include <iostream>
#include <string>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

int main(){
	std::string s="Hello, World!";

	// How does std::move work?
	// 1. Marks s as an RValue (normally, it's an LValue)
	// 2. By doing so, it activates the move constructor of m
	// 3. So, internally, the objects are swapped
	std::string m=std::move(s);

	// Verification:
	std::cerr<<"s is empty: "<<s<<std::endl;
	std::cerr<<"m contains: "<<m<<std::endl;
	return 0;
}
