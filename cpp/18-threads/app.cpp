#include <thread>
#include <iostream>

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

/* This runs as an independent thread */
void Thing::methodX(){
	std::cerr << "methodX called." << std::endl;
}

int main(){
	Thing thing;
	return 0;
}
