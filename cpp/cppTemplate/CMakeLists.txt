cmake_minimum_required(VERSION 3.7)

# Root directory

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Here, the doxygen target is included
include(doc/doxygen/doxygen.cmake)

# And just include the directories to build
add_subdirectory(src)
add_subdirectory(lib/factorial)

# Add the tests
enable_testing()
add_subdirectory(test)
