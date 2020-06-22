cmake_minimum_required(VERSION 3.10)
project(helloworld)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Install configuration is: "Release"
set(CMAKE_BUILD_TYPE Release)
find_library(helloworldlib NAMES helloworld)

# Simple!
add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld ${helloworldlib})

install(TARGETS helloworld
	RUNTIME DESTINATION bin
)

