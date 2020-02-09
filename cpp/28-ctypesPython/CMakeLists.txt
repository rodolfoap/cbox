cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Static libs go to: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "Dynamic libs go to: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-c -fPIC")

add_library(hello SHARED hello.cpp)

# Equivalent to (CLIBS) -lm
target_link_libraries(hello m)
