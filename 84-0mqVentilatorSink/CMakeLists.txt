cmake_minimum_required(VERSION 3.10)
project(VentilatorSink)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Fmt lib
find_package(fmt REQUIRED CONFIG)

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

add_executable(vrsink vrsink.cpp)
add_executable(worker worker.cpp)

# Equivalent to (CLIBS) -lm
target_link_libraries(vrsink zmq pthread fmt::fmt)
target_link_libraries(worker zmq pthread fmt::fmt)
