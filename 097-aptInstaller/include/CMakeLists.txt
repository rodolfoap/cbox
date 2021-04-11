add_library(${PROJECT_NAME}_header INTERFACE)

# /usr/local/include/helloworld.hpp
install(FILES ${PROJECT_SOURCE_DIR}/include/helloworld.hpp DESTINATION include)
