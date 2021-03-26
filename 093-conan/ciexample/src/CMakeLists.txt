add_library(${PROJECT_NAME} helloworld.cpp)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>)
