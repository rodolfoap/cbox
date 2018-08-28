cmake_minimum_required(VERSION 3.7)

# Generates the content in src/
add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/solid.cpp)
# Includes
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# This allows linking along with factorial.a
target_link_libraries(main factorial)

# If doxygen is available, generate the documentation
if(TARGET doxygen)
    add_doxygen(main)
endif()
