#include <stdio.h>


int main(){
// 	1. Example simple
	struct person1{ int age; };

	// Error
	// person0 p;
	// Valid
	struct person1 p={1};

	printf("p=%d\n", p);

//	2. Improved example, using typedef
	struct person2{ int age; };
	typedef struct person2 guy;
	guy q={2};
	printf("q=%d\n", q);

//	3. Which is the same as...
	struct person3{ int age; };
	typedef struct person3 person3;
	person3 r={3};
	printf("r=%d\n", r);

//	4. Joining the first two lines...
	typedef struct person4{ int age; } person4;
	person4 s={4};
	printf("s=%d\n", s.age);

	return 0;
}
