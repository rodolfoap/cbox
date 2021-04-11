add_library(${PROJECT_NAME}_lib SHARED helloworld_lib.cpp)
target_include_directories(${PROJECT_NAME}_lib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>)

set_target_properties(${PROJECT_NAME}_lib PROPERTIES OUTPUT_NAME helloworld)

# /usr/local/lib/libhelloworld.so; the EXPORT in the following line is used below
install(TARGETS ${PROJECT_NAME}_lib EXPORT ${PROJECT_NAME}Config)

# /usr/local/cmake/helloworld/helloworldConfig.cmake
# /usr/local/cmake/helloworld/helloworldConfig-release.cmake
install(EXPORT ${PROJECT_NAME}Config
	DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/${CMAKE_PROJECT_NAME}"
	NAMESPACE ${PROJECT_NAME}::
)

# /usr/local/cmake/helloworld/helloworldConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	VERSION 0.1
	COMPATIBILITY AnyNewerVersion
)
install(FILES
	${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/${CMAKE_PROJECT_NAME}"
)
