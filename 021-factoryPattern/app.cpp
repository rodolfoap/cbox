#include <iostream>
class Thing{
public:
	// Will return an object on the stack, a common variable.
	static Thing getThing(){
		Thing thing;
		return thing;
	}
	// Will return an object on the heap, necessarily, a pointer.
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
	// Stack access
	thing1.sayHi();

	/* Using pointer constructors */
	Thing* thing2=Thing::getThingAsPointer();
	// Heap access
	thing2->sayHi();
	return 0;
}
// Creating an object as "Thing thing1;" uses the stack, which is normal
// Creating an object as "Thing *thing1=new Thing();" uses the heap, which is usually complex
