cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Fmt lib: requires apt install libfmt-dev
find_package(fmt REQUIRED CONFIG)

add_executable(app app.cpp)
target_link_libraries(app fmt::fmt)
