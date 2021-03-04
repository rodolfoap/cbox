cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app app.c)
set_property(TARGET app PROPERTY C_STANDARD 90)
