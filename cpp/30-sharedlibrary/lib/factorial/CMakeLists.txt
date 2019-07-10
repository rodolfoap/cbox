cmake_minimum_required(VERSION 3.7)

add_library(factorial SHARED factorial.cpp)
target_include_directories(factorial PUBLIC include)
