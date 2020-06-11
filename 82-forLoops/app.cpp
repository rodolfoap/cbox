#include <iostream>
#include <algorithm>
#include <vector>
#define log(text)(std::cerr<<text<<std::endl)

int main(){
	// Common
	for(int i=0; i<10; i++) log(i);

	// Collection-based
	for(int i: {1, 2, 3, 5, 8, 13, 21, 34}) log(i);

	// Vector-based
	std::vector<int>k={1, 2, 3, 5, 8, 13, 21, 34};
	for(auto i: k) log(i);

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

	return 0;
}
