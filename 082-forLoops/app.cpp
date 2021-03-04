#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#define log(text)(std::cerr<<text<<std::endl)

int main(){
	// Common
	for(int i=0; i<10; i++) log(i);

	// Collection-based
	for(int i: {1, 2, 3, 5, 8, 13, 21, 34}) log(i);

	// Filling an array with a sequence starting from 100
	// [&a] [&a+1] [&a+2] == {100, 101, 102}
	// [&a+3 not included]
	int a[3];
	std::iota(a, a+3, 100);
	for(int& i: a) log(i);

	// Vector-based
	std::vector<int>k={1, 2, 3, 5, 8, 13, 21, 34};
	for(auto& i: k) log(i);

	// Array-based
	int j[]={1, 2, 3, 5, 8, 13, 21, 34};
	for(int& i: j) {
		i*=i; // Values can be modified
		log(i);
	}
	int qty=sizeof(j)/sizeof(j[0]);
	log(qty);
	auto itr=std::find(j, j + qty, (int)13);
	log(std::distance(j, itr));

	// Avoid strlen()
	char s[]="0123456789\0abcdefg";
	for(int i=0; s[i]; i++) log(s[i]); // prints 10 chars
	for(char& c: s) log(c); // prints 19 chars!

	return 0;
}
