cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

# Testing lib
find_package(Catch2 CONFIG REQUIRED)
include(CTest)
include(Catch)

add_library(reverse SHARED reverse.cpp)

add_executable(app app.cpp)
# Equivalent to (CLIBS) -lreverse
target_link_libraries(app reverse)

add_executable(testapp ./test_app.cpp)
target_link_libraries(testapp reverse Catch2::Catch2)
add_test(NAME testapp COMMAND testapp)
catch_discover_tests(testapp)
