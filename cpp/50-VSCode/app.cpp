#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(){
	std::cerr<<"Hello, World!"<<std::endl;
	return 0;
}
/*

- Start the app with "code ."
- FILE/Preferences/Extensions: Install CMake Tools and C/C++ Extensions
- Below, on the status bar, click on "Build" 
- Run with [Shift][F5]

*/