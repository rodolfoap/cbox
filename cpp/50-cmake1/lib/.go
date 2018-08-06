vi -p CMakeLists.txt src/structure.c src/include/structure.h
[ -d build ] && rm -r build/
mkdir build;
pushd build;
cmake ..;
make
popd
