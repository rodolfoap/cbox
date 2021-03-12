#include<iostream>
#define log(text)(std::cerr<<text<<std::endl)

class Hello {
public:
        void sayHello() { std::cerr<<"Hello, World!\n"; }
        void printFloat(double input) { std::cout<<"printFloat(): "<<input<<std::endl; }
        int doubleMe(int input) { return 2 * input; }
        const char* sayHelloName(char* name){
                static std::string s="Hello, ";
                s+=name;
                return s.c_str();
        }
};

extern "C" {
        Hello* helloFactory()					{ return new Hello(); }
        void sayHello(Hello* hello)				{ hello->sayHello(); }
        void printFloat(Hello* hello, double input)		{ return hello->printFloat(input); }
        int doubleMe(Hello* hello, int input)			{ return hello->doubleMe(input); }
        const char *sayHelloName(Hello* hello, char* name)	{ return hello->sayHelloName(name); }
}

int main(){
	char name[]="Thelonious";
	Hello* k=helloFactory();

	k->sayHello();
	k->printFloat(19.17);
	std::cout<<"Double of 19: "<<k->doubleMe(19)<<std::endl;
	std::cout<<k->sayHelloName(name)<<std::endl;

	delete k;
	return 0;
}
