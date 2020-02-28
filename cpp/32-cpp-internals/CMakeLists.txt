cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 17)
message(STATUS "Compiler: " CMAKE_CXX_COMPILER_ID)
set(CMAKE_CXX_FLAGS "-Os") # See https://gcc.gnu.org/onlinedocs/gcc-4.9.2/gcc/Optimize-Options.html
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(app app.cpp)
