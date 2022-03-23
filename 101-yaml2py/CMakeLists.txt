cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

execute_process(
	COMMAND conan install "${CMAKE_CURRENT_SOURCE_DIR}" --build missing
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(yaml-cpp REQUIRED)

add_executable(app app.cpp)
target_link_libraries(app yaml-cpp::yaml-cpp)
