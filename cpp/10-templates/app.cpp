#include<iostream>
#include<string>

template<class T> class Calculator{
public:
	T mul(T x, T y){return x*y;}
	T add(T x, T y){return x+y;}
};

int main(){
	Calculator<int> iCalculator;
	std::cout << iCalculator.add(8, 9) << std::endl;
	Calculator<float> fCalculator;
	std::cout << fCalculator.add(8.0, 9.0) << std::endl;
	return 0;
}
// Templates are to c what Generics are to Java; //definition is: template<class T> class Calculator; usage is: Calculator<int> calculator;
