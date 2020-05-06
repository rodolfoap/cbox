#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unistd.h>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
std::vector<std::vector<bool>> grid;
std::vector<std::vector<int>> igrid;

int getNeigh(int y, int x, int h, int w) {
	if(x>0 && y>0 && x<(w-1) && y<(h-1)) return grid[y][x]?1:0;
	return 0;
}

int main() {
	// Read binary file
	std::ifstream infile("binary.array");
	std::string line;
	while(std::getline(infile, line)) {
		std::vector<bool> temp;
		int value;
		// With each line, create an istringstream...
		std::istringstream iss(line);
		// ... and load it into the vector.
		while(iss>>value) { temp.push_back(value==1?true:false); }
		grid.push_back(temp);
	}
	int height=grid.size();
	int width=grid[0].size();
	while(true) {
		std::cout<<"\033[2J\033[1;1H"; // cls
		for(int y=0; y<height; y++) {
			for(int x=0; x<width; x++) std::cerr<<(grid[y][x]?'#':'.')<<' ';
			std::cerr<<std::endl;
		}
		std::cerr<<std::endl;
		igrid=std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
		for(int y=0; y<height; y++) {
			for(int x=0; x<width; x++) {
			//	igrid[y][x]+=getNeigh(y-1, x-1, height, width);
			//	igrid[y][x]+=getNeigh(y-1, x  , height, width);
			//	igrid[y][x]+=getNeigh(y-1, x+1, height, width);
				igrid[y][x]+=getNeigh(y  , x-1, height, width);
			//igrid[y][x]+=getNeigh(y  , x+1, height, width);
			//	igrid[y][x]+=getNeigh(y+1, x-1, height, width);
			//	igrid[y][x]+=getNeigh(y+1, x  , height, width);
			//	igrid[y][x]+=getNeigh(y+1, x+1, height, width);
				switch(igrid[y][x]) {
					case 3: grid[y][x]=true; break;
					case 2: break;
					default: grid[y][x]=false;
				}
				std::cerr<<igrid[y][x]<<" ";
			}
			std::cerr<<std::endl;
		}
		usleep(5000000);
	}
	return 0;
}

