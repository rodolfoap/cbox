cmake_minimum_required(VERSION 3.7)

add_executable(mytest src/main.c)

add_subdirectory(lib/)
include_directories(lib/src/include)
target_link_libraries(mytest mylib)
