#include<iostream>
#include<string>

template<class T> class Calculator{
public:
	T mul(T x, T y){return x*y;}
	T add(T x, T y){return x+y;}
};

int main(){
	Calculator<int> calculator;
	std::cout << calculator.add(8, 9) << std::endl;
	return 0;
}
// Templates are to c what Generics are to Java; //definition is: template<class T> class Calculator; usage is: Calculator<int> calculator;
