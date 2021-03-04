#include<iostream>
#include<vector>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int n=0;

struct Ball {
	int id;

	// Runs once: during the creation of the vector, this is the original
	// this runs only for ball 0
	Ball(): id(n)              { std::cerr<<n++<<" - Default constructor\n"; }

	// Runs 7 times! the original object is copied to each entry
	// this runs for balls 1, 2, 3, 4, 5, 6, 7
	Ball(const Ball& b): id(n) { std::cerr<<n++<<" - Copy constructor\n"; }

	void checkCollision(const Ball& b) {
		std::cerr<<"Me: "<<id<<"; other: "<<b.id<<std::endl;
	}
};

int main() {
	// Creates a vector with 7 balls
	// Ball 0 dies here, after being copied as 1, 2, 3, 4, 5, 6, 7
	std::vector<Ball> balls(7, Ball());

	for(Ball& ball: balls) {
		std::cerr<<"This is ball #"<<ball.id<<std::endl;
	}
	for (std::vector<Ball>::iterator ball=balls.begin(); ball!=balls.end(); ++ball) {
		for (std::vector<Ball>::iterator ball2=ball+1; ball2!=balls.end(); ++ball2) {
			std::cerr<<"Interaction: #"<<ball->id<<" - #"<<ball2->id<<std::endl;
		}
	}
	return 0;
}
