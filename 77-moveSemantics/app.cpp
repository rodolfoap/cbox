#include <iostream>
#include <cstring>

class Ztring{
private:
	char* data;
	uint32_t size;
public:
	// Never used
	Ztring()=default;

	// Used to construct a Ztring in [1]
	Ztring(const char* text){
		printf("Z.Constructor\n");
		size=strlen(text);
		data=new char[size];
		memcpy(data, text, size);
	}
	// Never used, since it takes an lvalue
	Ztring(const Ztring& other){
		printf("Z.Copy Constructor&: NOT USED\n");
		size=other.size;
		data=new char[size];
		memcpy(data, other.data, size);
	}
	// Explicitly called in [2], to use an rvalue
	Ztring(Ztring&& other){
		printf("Z.Move Constructor&&\n");
		size=other.size;
		data=other.data;
		other.size=0;
		other.data=nullptr;
	}
	// Object destroyed
	~Ztring(){
		printf("Z.Destructor\n");
		delete data;
	}
	void print(){
		printf("\t");
		for(uint32_t i=0; i<size; ++i) printf("%c", data[i]);
		printf("\n");
	}
};

class Entity{
private:
	Ztring name;
public:
	// Not used, since it takes an lvalue
	Entity(const Ztring&  aname): name(aname) { printf("E.Constructor&: NOT USED \n"); }

	// This is used, takes an rvalue, which will be modified.
	// In order to call the move constructor in the Ztring class,
	// the lvalue needs to be casted as an rvalue (Ztring&&).
	Entity(   Ztring&& aname): name((Ztring&&)aname)  { printf("E.Move Constructor&&\n"); } // [2]
	// In practice, this is better:
	// Entity(Ztring&& aname): name(std::move(aname)) { } // [2]

	// THE BIG LESSON:
	// std::move(lvalue) returns an rvalue, that's basically telling the compiler to accept
	// cannibalizing the object

	void printName(){ name.print(); }
};

int main(){
	Entity e("Hello, World!"); // [1]
	e.printName();
	printf("Done.\n");
	return 0;
}
