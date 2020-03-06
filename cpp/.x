[ -z "$1" ] && { echo "Usage: x [NNN-Title]"; return 1; }
[ e == "$1" ] && { echo "Usage: x [NNN-Title]"; return 1; }
[ -d "$1" ] && { echo "$1 already exists. Aborting."; return 1; }

mkdir $1
cat > $1/app.cpp << EOF
#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(){
	std::cerr<<"Hello, World!"<<std::endl;
	return 0;
}
EOF
cp -r 02-streams/{CMakeLists.txt,.k,.x} $1
find $1 -type f
cd $1
x
