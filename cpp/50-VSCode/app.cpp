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

settings.json:
{
    "explorer.confirmDelete": false,
    "C_Cpp.updateChannel": "Insiders",
    "cmake.configureOnOpen": true,
    "workbench.startupEditor": "newUntitledFile",
    "editor.insertSpaces": false,
    "editor.tabSize": 8,
    "editor.tabCompletion": "on",
    "editor.fontFamily":  "Terminus \\(TTF\\)",
    "editor.fontSize": 18
}
*/