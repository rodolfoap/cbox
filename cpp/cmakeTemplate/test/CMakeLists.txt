cmake_minimum_required(VERSION 3.7)

# Generates the content in src/
add_executable(unit_tests ${CMAKE_CURRENT_SOURCE_DIR}/test1.cpp)
# Includes
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# This allows linking along with factorial.a
target_link_libraries(unit_tests factorial)

# Tests are added
add_test(
  NAME unit_tests
  COMMAND unit_tests -o report.xml -r junit)

add_custom_command(
     TARGET unit_tests
     COMMENT "Run tests"
     POST_BUILD
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
)
