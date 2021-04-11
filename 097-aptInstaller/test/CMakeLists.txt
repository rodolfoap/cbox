add_executable(${PROJECT_NAME}_test helloworld_test.cpp)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME}_test PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>)

add_executable(${PROJECT_NAME}_test2 json_test.cpp)
target_link_libraries(${PROJECT_NAME}_test2 PRIVATE nlohmann_json::nlohmann_json)

add_test(NAME  test_${PROJECT_NAME} COMMAND helloworld_test)
add_test(NAME test2_${PROJECT_NAME} COMMAND helloworld_test2)
