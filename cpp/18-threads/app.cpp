#include <thread>
#include <iostream>

// PART 1
void fn(){
	for(int i=1; i<100; i++) std::cerr<<i<<' ';
	std::cerr << std::endl;
}
void caller(){
	std::thread t(fn);
	for(int i=1; i<100; i++) std::cerr<<'.';
	std::cerr << std::endl;

	// If no join() or detach() an active exception is thrown.
	// t.join();
	t.detach();
	if(t.joinable()) t.join(); else std::cerr <<"Thread not joinable."<< std::endl;
}

// PART 2
class Thing{
public:
	Thing(){
		std::cerr << "Constructor called." << std::endl;
		std::thread thread=this->spawn();
		thread.join(); /* or thread.detach(); */
	}
	std::thread spawn(){
		return std::thread(&Thing::methodX, this);
	}
	void methodX();
};
void Thing::methodX(){ std::cerr << "methodX called." << std::endl; }

int main(){
// PART 1
	caller();
// PART 2
	// Thread in object
	Thing thing;
	return 0;
}
