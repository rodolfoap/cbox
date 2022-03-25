cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_library(hello SHARED hello.cpp hello_c.cpp)
target_include_directories(hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test test.cpp hello.cpp)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test_c test_c.cpp hello.cpp hello_c.cpp)
target_include_directories(test_c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
