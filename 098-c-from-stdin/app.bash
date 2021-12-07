#!/bin/bash

cat << EOF|g++ -x c++ -
#include<iostream>
int main(){std::cout<<"Hello World!
return 0; }
EOF
