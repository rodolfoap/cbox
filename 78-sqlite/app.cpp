#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
typedef struct Register{
	uint id;
	std::string name;
	int zone;
	float score;
	std::string state;
	void print(){ printf("%d:%s:%d:%f:%s\n", id, name.c_str(), zone, score, state.c_str()); }
} Register;
void save(){
	char data[4][64] {	"1927 Frank_Holdsworth 62 0.3272 Arizona",
				"1862 Jim_Scofield 32 0.1323 Arkansas",
				"6271 Thelonious_Grenadier 44 0.42864 Missouri",
				"8261 Albert_Swallow 51 0.28674 Toronto"};
	std::ofstream outFile;
	outFile.open("table.data");
	for(int i=0; i<4; ++i) outFile<<data[i]<<std::endl;
	outFile.close();
}
int main() {
	save();
	std::ifstream inFile;
	inFile.open("table.data");
	if(!inFile.is_open()) return 1;
	std::string line;
	while(getline(inFile, line)) {
		Register r;
		std::istringstream ss(line);
		ss >> r.id >> r.name >> r.zone >> r.score >> r.state;
		ss.str("");
		r.print();
	}
	inFile.close();
	return 0;
}
