#include <iostream>
#include <fmt/format.h> // See CMakeLists.txt

int main(){
	std::cerr<<fmt::format("Hello {}!\n", "world");
	return 0;
}
