cmake_minimum_required(VERSION 3.10)
project(app)

find_package(Java REQUIRED)
include(UseJava)
set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")
set(JAVA_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(JAVA_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Subscriber.java)
set(CMAKE_JAVA_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/jeromq-0.4.3.jar)
add_jar(Subscriber
	SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Subscriber.java
	INCLUDE_JARS ${CMAKE_CURRENT_SOURCE_DIR}/jeromq-0.4.3.jar
	ENTRY_POINT Subscriber
	OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Force C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

add_executable(publisher publisher.cpp)
add_executable(subscriber subscriber.cpp)

# Equivalent to (CLIBS) -lm
target_link_libraries(publisher zmq)
target_link_libraries(subscriber zmq)
