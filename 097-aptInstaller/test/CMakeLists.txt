add_executable(${PROJECT_NAME}_test helloworld_test.cpp)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME}_test PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>)

add_test(NAME test_${PROJECT_NAME} COMMAND helloworld_test)
