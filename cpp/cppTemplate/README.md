# CppSkeleton

Based on https://github.com/yoyomatsu/DoxygenCmake

Includes:

* Cmake Standard build pipe, example with static lib
* Doxygen documentation
* Catch2 unit tests

## Howto

* Edit the CMakeLists.txt according to the structure of your project, add doxygen to each node.
```
if(TARGET doxygen)
    add_doxygen(main)
endif()
```
* Create your tests and complete the tests/CMakeLists.txt with all the tests to include:
```
add_test(
  NAME unit_tests
  COMMAND unit_tests -o report.xml -r junit)
```

* Leave or remove the option to execute the tests during build
```
add_custom_command(
     TARGET unit_tests
     COMMENT "Run tests"
     POST_BUILD
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
)
```
* Run the cmake command chain:
```
mkdir build
cd build
cmake ..
make
```
* Generate doxygen files by running the make command inside the build/ directory:
```
make doxygen
```

You can also generate single target document by `make doxygen-TARGET`.

```
make doxygen-factorial
```
Then, you can find document in  `/doc/TARGET`.
