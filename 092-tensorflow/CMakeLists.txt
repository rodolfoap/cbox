cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app app.cpp)
target_link_libraries(app tensorflow)
