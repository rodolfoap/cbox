rm --interactive=never -rf build/;
mkdir build;
pushd build;
cmake .. -Wdev;
make -j8
popd;
