#!/bin/bash
set -x

cd $(cd $(dirname "${BASH_SOURCE[0]}")&>/dev/null&&pwd)
. VERSION
rm -rf build;
mkdir -p build;
pushd build &> /dev/null;
[ -f Makefile ] || cmake .. -Wdev -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Release
make -j$(nproc);
echo -e '----------------------------------------------------------------------------------------------------\nTEST:\n'
ctest --verbose;
echo -e '----------------------------------------------------------------------------------------------------\nDEB:\n'
#/usr/bin/sudo /bin/chown -R $(/usr/bin/id -un): .
cpack
dpkg -I helloworld-*-linux.deb
dpkg -c helloworld-*-linux.deb
popd &> /dev/null;
