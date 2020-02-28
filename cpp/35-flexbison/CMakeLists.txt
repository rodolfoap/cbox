cmake_minimum_required(VERSION 3.10)
project(app)

# # Force C++11
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# 
# # Equivalent to (CFLAGS) -g
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
# 
# # Equivalent to (CFLAGS) -g
# set(CMAKE_C_FLAGS "-g")
# 
# # Equivalent to (CLIBS) -lm
# target_link_libraries(app m)

find_package(BISON)
find_package(FLEX)

add_definitions(-D_DEBUG -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS)

BISON_TARGET(bcalc bcalc.y ${CMAKE_CURRENT_BINARY_DIR}/bcalc.tab.cpp)
FLEX_TARGET (fcalc fcalc.l ${CMAKE_CURRENT_BINARY_DIR}/fcalc.cpp)
ADD_FLEX_BISON_DEPENDENCY(fcalc bcalc)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(app ${BISON_bcalc_OUTPUTS} ${FLEX_fcalc_OUTPUTS})
