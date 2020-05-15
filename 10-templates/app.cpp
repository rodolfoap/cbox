#include<iostream>
#include<string>

/* Instead of defining...

void PrintSomething(int s){}
void PrintSomething(std::string s){}

We just define...  */

template <typename T> void PrintSomething(T s){ std::cout << s << std::endl; }

/* This even applies to classes, instead of doing...

class Entity{
private:
	int list[5];
public:
	void bytelen(){ std::cout << sizeof(list) << std::endl; }
};

...
Entity e;
e.printsize();

We just define...  */

template <typename T, int S> class Entity{
private:
	T list[S];
public:
	void bytelen(){ std::cout << sizeof(list) << std::endl; }
};

int main(){

	PrintSomething(13);
	PrintSomething("Hello, World!");
	PrintSomething(3.14f);

	Entity<int, 9> e;
	e.bytelen();
	return 0;
}
// Templates are to c what Generics are to Java;
