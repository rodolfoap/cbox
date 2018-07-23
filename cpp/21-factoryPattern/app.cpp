#include <iostream>
class Thing{
public:
	static Thing getThing(){
		Thing thing;
		return thing;
	}
	static Thing* getThingAsPointer(){
		return new Thing();
	}
	void sayHi(){
		std::cerr << "Hi." << std::endl;
	}
};

int main() {
	/* Using standard constructors */
	Thing thing1=Thing::getThing();
	thing1.sayHi();

	/* Using pointer constructors */
	Thing* thing2=Thing::getThingAsPointer();
	thing2->sayHi();
	return 0;
}
// Creating an object as "Thing thing1;" uses the stack;
// Creating an object as "Thing *thing1=new Thing();" uses the heap;
