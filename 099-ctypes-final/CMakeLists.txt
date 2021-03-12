cmake_minimum_required(VERSION 3.10)
project(app)
# See https://github.com/sol-prog/Python-using-C-CPP-libraries-with-ctypes

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_library(holder SHARED holder.cpp secbroker.cpp)
target_include_directories(holder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
