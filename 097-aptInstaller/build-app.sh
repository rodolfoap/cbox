#!/bin/bash
set -x

cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION
rm -rf build;
mkdir -p build;
pushd build &> /dev/null;
[ -f Makefile ] || cmake .. -Wdev -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Release
make -j$(nproc);
ctest --verbose;
cpack
dpkg -I helloworld-*-linux.deb
dpkg -c helloworld-*-linux.deb
popd &> /dev/null;
