vi -p CMakeLists.txt src/main.c
[ -d build ] && rm -r build/
mkdir build;
pushd build;
cmake ..;
make
popd
