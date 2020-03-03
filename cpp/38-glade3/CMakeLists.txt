cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMakeLists.txt contents:")
execute_process(COMMAND sed "s/^/\t/" CMakeLists.txt
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	RESULT_VARIABLE CMD_ERROR)

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

# GTK3++
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(app app.cpp)

# Equivalent to (CLIBS) -lm
target_link_libraries(app ${GTK3_LIBRARIES})
