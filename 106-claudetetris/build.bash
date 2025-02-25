#!/bin/bash
cd $(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

[ -d build/ ] && {
	pushd build &> /dev/null;
} || {
	mkdir build;
	pushd build &> /dev/null;
	cmake .. -Wdev;
}
make -j8; STATUS=$?
popd &> /dev/null;
#rm -rf build
[ $STATUS == 0 ] && echo [100%] $(ls -l opticalflow) || echo [ERROR] Compilation error.
