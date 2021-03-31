cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Conan -------------------------
execute_process(
	COMMAND conan install "${CMAKE_CURRENT_SOURCE_DIR}" --build missing
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
# Option 1: use generators: cmake in conanfile.txt
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(NO_OUTPUT_DIRS)

# Option 2: use generators: cmake_paths and cmake_find_package in conanfile.txt
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Poco REQUIRED)
# Conan end ---------------------

add_executable(app app.cpp)

# For Option 1:
target_link_libraries(app ${CONAN_LIBS})
# For Option 2:
target_link_libraries(app Poco::Poco)
