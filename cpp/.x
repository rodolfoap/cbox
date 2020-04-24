[    -z "$1" ] && { echo "Usage: x [Title]"; return 1; }
[  e == "$1" ] && { echo "Usage: x [Title]"; return 1; }

DIR=$(echo 1+$(ls -d1 [0-9]*|sort|cut -f1 -d'-'|tail -1)|bc)-$1
mkdir $DIR
cat > $DIR/app.cpp << EOF
#include<iostream>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

int main(){
	std::cerr<<"Hello, World!"<<std::endl;
	return 0;
}
EOF
cp -r 02-streams/{CMakeLists.txt,.k,.x} $DIR
find $DIR -type f
cd $DIR
x
