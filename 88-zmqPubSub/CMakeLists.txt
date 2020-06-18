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

add_executable(pub pub.cpp message.cpp functions.cpp)
add_executable(sub sub.cpp message.cpp functions.cpp)
target_include_directories(pub PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(sub PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(pub zmq pthread fmt::fmt uuid)
target_link_libraries(sub zmq pthread fmt::fmt uuid)
