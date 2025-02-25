cmake_minimum_required(VERSION 3.10)
project(TetrisGame VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the ncurses package
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable target
add_executable(tetris main.cpp)

# Link against the ncurses library
target_link_libraries(tetris ${CURSES_LIBRARIES})

# Install target (optional)
install(TARGETS tetris DESTINATION bin)

# Add compile options for warnings (optional but recommended)
target_compile_options(tetris PRIVATE -Wall -Wextra)

# Output directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
