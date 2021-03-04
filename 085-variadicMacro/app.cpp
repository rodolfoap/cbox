#include<iostream>

template<typename ...T>
void log(T&& ...v) {
	(std::cerr<<...<<v) <<std::endl;
}
int main(){
	log("Hello, World!", 1, ':', ':');
	return 0;
}
