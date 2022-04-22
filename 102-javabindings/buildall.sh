#!/bin/bash
set -x

GROUPNAME=eu.acme.bindings
CLASSNAME=Bindings

NATIVE_ACCESSER_PATH=$(echo ${GROUPNAME}|tr '.' '/')/${CLASSNAME}.java
NATIVE_ACCESSER_CLASS_NAME=${GROUPNAME}.${CLASSNAME}

# Generate headers
javac -h . $(echo ${GROUPNAME}|tr '.' '/')/${CLASSNAME}.java
mv -v $(echo ${GROUPNAME}|tr '.' '_')_${CLASSNAME}.h ${CLASSNAME}.hpp

# Build
rm -rf build
mkdir build && pushd build
cmake ../
make -j $(nproc)
popd

# Run library
javac ${NATIVE_ACCESSER_PATH}
java ${NATIVE_ACCESSER_CLASS_NAME} -D$(pwd)/../../build
