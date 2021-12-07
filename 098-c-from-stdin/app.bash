#!/bin/bash
set -x

cat << EOF|g++ -x c++ -
#include<iostream>
int main(){
std::cout<<"Hello World!"<<std::endl;
return 0;
}
EOF
./a.out

echo -e "#include<iostream>\nint main(){std::cout<<\"Hello World!\"<<std::endl;return 0;}"|g++ -x c++ -
./a.out
