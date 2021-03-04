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

	// STACK

	// Create a std::stack of std::strings.
	std::stack <std::string> distros;
	//Pushing elements into the std::stack.
	distros.push("Ubuntu");
	distros.push("Mint");
	std::cout << "std::stack size(): " << distros.size() << std::endl;
	//	std::stack size(): 2

	std::cout << "std::stack  top(): " << distros.top() << std::endl;
	//	std::stack  top(): Mint

	distros.pop();
	std::cout << "std::stack  top(): " << distros.top() << std::endl;
	//	std::stack  top(): Ubuntu

	// VECTOR

	std::vector <int> nvec;
	// Vector is empty
	std::cout << "std::vector empty() :" << (nvec.empty()?"TRUE":"FALSE") << std::endl;
	//	std::vector empty() :TRUE

	std::cout << "std::vector  size() :" << nvec.size() << std::endl;
	//	std::vector  size() :0

	// Add values
	for(int i=0; i<10; i++) { nvec.push_back(i); }
	std::cout << "std::vector empty() :" << (nvec.empty()?"TRUE":"FALSE") << std::endl;
	//	std::vector empty() :FALSE

	std::cout << "std::vector  size() :" << nvec.size() << std::endl;
	//	std::vector  size() :10

	// Iterating
	std::vector <int>::iterator it;
	std::cout<<"std::vector: "; for(it=nvec.begin(); it!=nvec.end(); it++) std::cout<<*it<<" "; std::cout<<std::endl;
	//	std::vector: 0 1 2 3 4 5 6 7 8 9

	// getting value at particular position
	int pos = 5;
	std::cout<<"std::vector("<<pos<<")=="<<nvec.at(pos)<<std::endl;
	//	std::vector(5)==5

	// deleting an element at position
	nvec.erase(nvec.begin()+pos);
	std::cout<<"std::vector: "; for(it=nvec.begin(); it!=nvec.end(); it++) std::cout<<*it<<" "; std::cout<<std::endl;
	//	std::vector: 0 1 2 3 4 6 7 8 9

	// deleting range (elements 1 to 3)
	// You may expect elements at 1, 2 and 3 to be deleted, but index 3 is not inclusive.
	nvec.erase(nvec.begin()+1, nvec.begin()+3);
	std::cout<<"std::vector: "; for(it=nvec.begin(); it!=nvec.end(); it++) std::cout<<*it<<" "; std::cout<<std::endl;
	//	std::vector: 0 3 4 6 7 8 9

	// Clearing the std::vector
	nvec.clear();
	std::cout << "std::vector empty() :" << (nvec.empty()?"TRUE":"FALSE") << std::endl;
	//	std::vector empty() :TRUE

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
	//	std::map:
	//	(Facebook, Mark Zuckerberg)
	//	(Google, Larry Page)
	//	(Quora, Adam D'Angelo)
	//	(Uber, Travis Kalanick)
	//	(Xarvis Tech, Xarvis Le Pen)

	// Finding, verifying
	m=hmap.find("Google");
	if(m==hmap.end()){ std::cout<<"Not found"<<std::endl; } else { std::cout<<"Found: "<<m->second<<std::endl; }
	//	Found: Larry Page

	// LINKED LISTS

	std::list<int> llist;
	std::list<int>::iterator it1,it2,itx;
	// Add values: 0 10 20 30 40 50 60 70 80 90
	for(int i=0; i<10; ++i) llist.push_back(10*i);
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;
	//	std::list: 0 10 20 30 40 50 60 70 80 90

	// Navigating, removing
	it1=it2=llist.begin();	// At [0]
	++it1;			// At [10]
	int index=std::distance(llist.begin(), it1);
	std::cout<<"std::list["<<index<<"]: "<<*it1<<std::endl;
	//	std::list[1]: 10

	it1=llist.erase(it1);	// Removes [10]
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;
	//	std::list: 0 20 30 40 50 60 70 80 90

	advance(it2,6);		// At [60]
	std::cout<<"std::list["<<std::distance(llist.begin(), it2)<<"]: "<<*it2<<std::endl;
	//	std::list[6]: 70

	it2=llist.erase(it2);   // Removes [70]
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;
	//	std::list: 0 20 30 40 50 60 80 90

	// Removing range
	++it1;
	--it2;
	std::cout<<"std::list[(it1)"<<std::distance(llist.begin(), it1)<<"]: "<<*it1<<std::endl;
	//	std::list[(it1)2]: 30

	std::cout<<"std::list[(it2)"<<std::distance(llist.begin(), it2)<<"]: "<<*it2<<std::endl;
	//	std::list[(it2)5]: 60

	llist.erase(it1,it2);
	std::cout<<"std::list:"; for(itx=llist.begin(); itx!=llist.end(); ++itx) std::cout<<" "<<*itx; std::cout<<std::endl;
	//	std::list: 0 20 60 80 90

	// it1 still points to 30, and 60 was not deleted
	std::cout<<"it1: "<<*it1<<"(already deleted); it2: "<<*it2<<std::endl;
	//	it1: 30(already deleted); it2: 60

	// This will print an unexpected value
	std::cout << *it1++ << std::endl;
	//	30

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
	while (!pq.empty()) { std::cout << pq.top() << "[" << pq.size() << "] " <<std::endl; pq.pop(); }
	//	1[5]
	//	5[4]
	//	10[3]
	//	20[2]
	//	30[1]

	// Creating heap from user defined objects
	p1.name = "Linus Torvalds"; p1.age = 47;
	p2.name = "Elon Musk"; p2.age = 46;
	p3.name = "Boris Johnsonson"; p3.age = 9;
	// Initialize a min heap
	// Note: We defined a comparator is_older in the beginning to compare the ages of two person.
	std::priority_queue <struct Person, std::vector<struct Person>, is_older> mh;
	mh.push(p1);
	mh.push(p2);
	mh.push(p3);
	while (!mh.empty()) { std::cout << mh.top().name << "[" << mh.size() << "] " <<std::endl; mh.pop(); }
	//	Boris Johnsonson[3]
	//	Elon Musk[2]
	//	Linus Torvalds[1]

	// SORTING

	// The following list type initialization is only supported after C++11
	std::vector<int> int_vec = {56, 32, -43, 23, 12, 93, 132, -154};

	// Ascending:
	// std::sort(int_vec.begin(), int_vec.end());
	// Descending:
	std::sort(int_vec.begin(), int_vec.end(), way_to_sort);
	for (std::vector <int>::iterator i=int_vec.begin(); i!=int_vec.end(); i++) std::cout << "int_vec[" << std::distance(int_vec.begin(), i) << "]:" <<*i << std::endl;
	//	int_vec[0]:132
	//	int_vec[1]:93
	//	int_vec[2]:56
	//	int_vec[3]:32
	//	int_vec[4]:23
	//	int_vec[5]:12
	//	int_vec[6]:-43
	//	int_vec[7]:-154

	// Sorting user-defined objects (apparently, it sums all the string chars).
	p1.name="Ccc";
	p2.name="BBBBB";
	p3.name="AAAAAA";
	static struct Person persons[] = {p1, p2, p3};
	std::sort(persons, persons+2, compare_names);
	for (int i=0; i < 3; i++) std::cout << persons[i].name << " " <<std::endl;
	//	BBBBB
	//	Ccc
	//	AAAAAA

	return 0;
}
