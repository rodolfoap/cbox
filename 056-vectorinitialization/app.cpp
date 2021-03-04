#include<iostream>
#include<vector>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int n=0;

struct Ball{
        int pos;

	// Runs once: during the creation of the vector, this is the original
	// this runs only for ball 0
        Ball(): pos(n)              { std::cerr<<n++<<" - Default constructor\n"; }

	// Runs 3 times! the original object is copied to each entry
	// this runs for balls 1, 2, 3
        Ball(const Ball& b): pos(n) { std::cerr<<n++<<" - Copy constructor\n"; }
};

int main(){
	// Creates a vector with 3 balls
	// Ball 0 dies here, after being copied as 1, 2, 3
	std::vector<Ball> balls(3, Ball());
	for(Ball& ball: balls) std::cerr<<"This is ball #"<<ball.pos<<std::endl;

	std::cerr<<"------------"<<std::endl;

	// Better: use vector.emplace_back() instead of push_back():
	// The problem of this is that the vector is doubled in size each
	// time there's no space, and all elements are re-copied
	std::vector<Ball> balls2;
	balls2.emplace_back(Ball());
	balls2.emplace_back(Ball());
	balls2.emplace_back(Ball());
	for(Ball& ball: balls2) std::cerr<<"This is ball #"<<ball.pos<<std::endl;

	std::cerr<<"------------"<<std::endl;

	// Better: use vector.emplace_back() instead of push_back():
	// AND vector.reserve()
	// The problem of this is that the vector is doubled in size each
	// time there's no space, and all elements are re-copied
	std::vector<Ball> balls3;
	balls3.reserve(3);
	// Notice the use of emplace_back() instead of emplace_back(Ball()):
	// The constructor should allow this, otherwise, copies will be created.
	balls3.emplace_back();
	balls3.emplace_back();
	balls3.emplace_back();
	for(Ball& ball: balls3) std::cerr<<"This is ball #"<<ball.pos<<std::endl;
	return 0;
}
