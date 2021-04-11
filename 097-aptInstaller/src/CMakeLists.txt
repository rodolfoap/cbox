add_executable(${PROJECT_NAME}_bin helloworld.cpp)
target_link_libraries(${PROJECT_NAME}_bin PRIVATE ${PROJECT_NAME}_lib nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME}_bin PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>)

# this avoids complains: '-- Set runtime path of "/usr/local/bin/helloworld" to ""'
set_target_properties(${PROJECT_NAME}_bin PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)

# better naming for binary
set_target_properties(${PROJECT_NAME}_bin PROPERTIES OUTPUT_NAME helloworld)

# /usr/local/bin/helloworld
install(TARGETS ${PROJECT_NAME}_bin DESTINATION bin)
