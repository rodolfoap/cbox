#include<iostream>
#include<string>
#include<iomanip>
class Base{
public:
	int a;
	std::string b="Hello, world!";
};
class Extension :public Base {
public:
	void setA(int);
	int getA();
};
void Extension::setA(int x){
	a=x;
}
int  Extension::getA(){
	return a;
}

template<class T> void dumpObject(T const *t) {
	unsigned char const *p=reinterpret_cast<unsigned char const*>(t);
	for (size_t n = 0 ; n < sizeof(T) ; ++n){
		printf("%02d ", p[n]);
	} printf("\n");

	const unsigned char *q=reinterpret_cast<const unsigned char*>(&t);
	for (size_t m = 0; m < sizeof(t); ++m) {
		std::cout << std::hex << std::setw(2) << static_cast<unsigned int>(q[m]) << " ";
	} printf("\n");
}


int main(){
	Extension xt;
	xt.setA(13);
	std::cout << xt.getA() << std::endl;
	dumpObject(&xt);
	return 0;
}
