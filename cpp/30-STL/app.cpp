// See https://gist.github.com/satwikkansal/c959e89161cc60db16b412233177feab
// A comprehensive include: #include <bits/stdc++.h>, see https://www.geeksforgeeks.org/bitsstdc-h-c

#include <iostream>

#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

struct Person {
	std::string name;
	int age;
} p1, p2, p3;

struct is_older {
	bool operator()(struct Person p1, struct Person p2) {
		return p1.age > p2.age;
	}
};

bool compare_names(struct Person p1, struct Person p2) {
	return p1.name < p2.name;
}

bool way_to_sort(int i, int j) { return i > j; }

int main() {
	/*

	// STACK

	// Create a std::stack of std::strings.
	std::stack <std::string> distros;
	//Pushing elements into the std::stack.
	distros.push("Ubuntu");
	distros.push("Mint");
	std::cout << "std::stack size(): " << distros.size() << std::endl;
	std::cout << "std::stack  top(): " << distros.top() << std::endl;
	distros.pop();
	std::cout << "std::stack  top(): " << distros.top() << std::endl;

	// VECTOR

	std::vector <int> nvec;
	// Vector is empty
	std::cout << "std::vector empty() :" << (nvec.empty()?"TRUE":"FALSE") << std::endl;
	std::cout << "std::vector  size() :" << nvec.size() << std::endl;
	// Add values
	for(int i=0; i<10; i++) { nvec.push_back(i); }
	std::cout << "std::vector empty() :" << (nvec.empty()?"TRUE":"FALSE") << std::endl;
	std::cout << "std::vector  size() :" << nvec.size() << std::endl;

	// Iterating
	std::vector <int>::iterator it;
	std::cout<<"std::vector: "; for(it=nvec.begin(); it!=nvec.end(); it++) std::cout<<*it<<" "; std::cout<<std::endl;
	// getting value at particular position
	int pos = 5;
	std::cout<<"std::vector("<<pos<<")=="<<nvec.at(pos)<<std::endl;

	// deleting an element at position
	nvec.erase(nvec.begin()+pos);
	std::cout<<"std::vector: "; for(it=nvec.begin(); it!=nvec.end(); it++) std::cout<<*it<<" "; std::cout<<std::endl;

	// deleting range (elements 1 to 3)
	// You may expect elements at 1, 2 and 3 to be deleted, but index 3 is not inclusive.
	nvec.erase(nvec.begin()+1, nvec.begin()+3);
	std::cout<<"std::vector: "; for(it=nvec.begin(); it!=nvec.end(); it++) std::cout<<*it<<" "; std::cout<<std::endl;

	// Clearing the std::vector
	nvec.clear();
	std::cout << "std::vector empty() :" << (nvec.empty()?"TRUE":"FALSE") << std::endl;

	// HASHMAP
	// Declaration: <key_type, value_type>
	std::map <std::string, std::string> hmap;
	hmap["Google"] = "Larry Page";
	hmap["Facebook"] = "Mark Zuckerberg";
	// Several insertion mechanisms:
	hmap.insert(std::pair<std::string, std::string> ("Xarvis Tech", "Xarvis Le Pen"));
	hmap.insert(std::map<std::string,std::string>::value_type("Quora", "Adam D'Angelo"));
	hmap.insert(std::make_pair(std::string("Uber"), std::string("Travis Kalanick")));
	// Iterating the map
	std::map<std::string, std::string>::iterator m;
	std::cout<<"std::map:"<< std::endl;
	for(m=hmap.begin(); m!=hmap.end(); m++) std::cout<<"("<<(*m).first<< ", "<<m->second<<")"<<std::endl;
	// Finding, verifying
	m=hmap.find("Google");
	if(m==hmap.end()){ std::cout<<"Not found"<<std::endl; } else { std::cout<<"Found: "<<m->second<<std::endl; }

	// LINKED LISTS

	std::list<int> llist;
	std::list<int>::iterator it1,it2,itx;
	// Add values: 0 10 20 30 40 50 60 70 80 90
	for(int i=0; i<10; ++i) llist.push_back(10*i);
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;

	// Navigating, removing
	it1=it2=llist.begin();	// At [0]
	++it1;			// At [10]
	int index=std::distance(llist.begin(), it1);
	std::cout<<"std::list["<<index<<"]: "<<*it1<<std::endl;
	it1=llist.erase(it1);	// Removes [10]
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;
	advance(it2,6);		// At [60]
	std::cout<<"std::list["<<std::distance(llist.begin(), it2)<<"]: "<<*it2<<std::endl;
	it2=llist.erase(it2);   // Removes [70]
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;

	// Removing range
	++it1;
	--it2;
	std::cout<<"std::list[(it1)"<<std::distance(llist.begin(), it1)<<"]: "<<*it1<<std::endl;
	std::cout<<"std::list[(it2)"<<std::distance(llist.begin(), it2)<<"]: "<<*it2<<std::endl;
	llist.erase(it1,it2);     // 10 30 60 80 90
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;
	// it1 still points to 30, and 60 was not deleted
	std::cout<<"it1: "<<*it1<<"(already deleted); it2: "<<*it2<<std::endl;
	// This will print an unexpected value
	std::cout << *it1++;

	*/

	// HEAPS

	// Creates a max heap: std::priority_queue<int> pq;
	// To create a min heap instead, just uncomment the below line
	std::priority_queue <int, std::vector<int>, std::greater<int> > pq;
	pq.push(30);
	pq.push(5);
	pq.push(1);
	pq.push(20);
	pq.push(10);
	// Extracting items from the heap
	while (!pq.empty()) { std::cout << pq.top() << " "; pq.pop(); } std::cout<<std::endl;

	// Creating heap from user defined objects
	p1.name = "Linus Torvalds"; p1.age = 47;
	p2.name = "Elon Musk"; p2.age = 46;
	p3.name = "Me!"; p3.age = 19;
	// Initialize a min heap
	// Note: We defined a comparator is_older in the beginning to
	// compare the ages of two person.
	priority_queue <struct Person, std::vector<struct Person>, is_older> mh;
	mh.push(p1);
	mh.push(p2);
	mh.push(p3);
	// Extracting items from the heap
	while (!mh.empty()) {
		struct Person p=mh.top();
		std::cout << p.name << " ";
		mh.pop();
	}

/*
	// SORTING

	// The following list type initialization is only supported after C++11
	//std::vector<int> int_vec = {56, 32, -43, 23, 12, 93, 132, -154};
	// If the above style of initialization doesn't work, use the following one
	static int arr[] = {56, 32, -43, 23, 12, 93, 132, -154};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	std::vector <int> int_vec(arr, arr + arr_len);
	std::cout << std::endl;
	// Default: sort ascending
	// sort(int_vec.begin(), int_vec.end());
	// To sort in descending order:
	// Do not include the () when you call wayToSort
	// It must be passed as a function pointer or function object
	sort(int_vec.begin(), int_vec.end(), way_to_sort);
	for (std::vector <int>::iterator i = int_vec.begin(); i!=int_vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	// sorting the array
	sort(arr, arr + arr_len);
	for (int i=0; i < arr_len; i++) {
		std::cout << arr[i] << " ";
	}
	// Sorting user-defined objects
	static struct Person persons[] = {p1, p2, p3};
	sort(persons, persons+3, compare_names);
	// This will printout the names in alphabetical order
	for (int i=0; i < 3; i++) {
		std::cout << persons[i].name << " ";
	}
	*/
	return 0;
}
