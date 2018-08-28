cmake_minimum_required(VERSION 3.7)

# Generates the content in src/
add_library(factorial STATIC ${CMAKE_CURRENT_SOURCE_DIR}/factorial.cpp)
# Includes: REMARK that this is PUBLIC, so it can be called from src/
target_include_directories(factorial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# If doxygen is available, generate the documentation
if(TARGET doxygen)
    add_doxygen(factorial)
endif()
