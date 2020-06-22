cmake_minimum_required(VERSION 3.10)
project(helloworld)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Install configuration is: "Release"
set(CMAKE_BUILD_TYPE Release)

# Generate the library
add_library(helloworld SHARED helloworld.cpp)
target_include_directories(helloworld PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Will include the header in the installers [1]
set_target_properties(helloworld PROPERTIES PUBLIC_HEADER include/helloworld.hpp)

install(TARGETS helloworld
	# Will install /usr/local/lib/libhelloworld.so
	LIBRARY DESTINATION lib
	# Will install /usr/local/include/helloworld.hpp [1]
        PUBLIC_HEADER DESTINATION include
)
