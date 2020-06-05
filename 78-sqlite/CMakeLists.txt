cmake_minimum_required(VERSION 3.10)
project(app)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMakeLists.txt contents:")
execute_process(COMMAND sed "s/^/\t/" CMakeLists.txt
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	RESULT_VARIABLE CMD_ERROR)

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#set(SFML_STATIC_LIBRARIES TRUE)

add_executable(app app.cpp)

# Equivalent to (CLIBS) -lm
# target_include_directories(gen-points PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_link_libraries(app m sfml-graphics sfml-window sfml-system sfml-audio ${OpenCV_LIBS} stdc++fs)
