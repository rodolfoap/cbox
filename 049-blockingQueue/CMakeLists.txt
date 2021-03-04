cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMakeLists.txt contents:")
execute_process(COMMAND sed "s/^/\t/" CMakeLists.txt
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	RESULT_VARIABLE CMD_ERROR)

find_package(Boost 1.67.0 REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

add_executable(app app.cpp)

target_link_libraries(app ${Boost_LIBRARIES})
#link_directories(${Boost_LIBRARY_DIRS})
