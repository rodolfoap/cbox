cmake_minimum_required(VERSION 3.16)

project(helloworld)
set(CMAKE_CXX_STANDARD 17)

execute_process(COMMAND cat VERSION COMMAND cut -f2 -d= WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE VERSION)
message("Library VERSION is: ${VERSION}")

# Don't run conan install within conan create!
option(IS_BUILDING_FROM_CONAN "Is running from conan create?" OFF)
if(NOT ${IS_BUILDING_FROM_CONAN})
	execute_process(
		COMMAND conan install "${CMAKE_CURRENT_SOURCE_DIR}" --build missing
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	)
endif()

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(nlohmann_json REQUIRED)

add_subdirectory(src)

# Installs /usr/local/include/helloworld.hpp
install(DIRECTORY include/ DESTINATION include)

# Installs /usr/local/lib/libhelloworld.a
install(TARGETS ${PROJECT_NAME}
	DESTINATION lib
	# Associates the target with the name ${PROJECT_NAME}Config
	EXPORT ${PROJECT_NAME}Config
)

# Config Helpers
include(CMakePackageConfigHelpers)

# Creates Version file
write_basic_package_version_file(
        ${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${VERSION}
        COMPATIBILITY AnyNewerVersion
)

# Installs /usr/local/lib/cmake/helloworld/helloworldConfigVersion.cmake
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/${CMAKE_PROJECT_NAME}"
)

# Installs /usr/local/lib/cmake/helloworld/helloworldConfig.cmake
# Installs /usr/local/lib/cmake/helloworld/helloworldConfig-noconfig.cmake
install(EXPORT ${PROJECT_NAME}Config
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/${CMAKE_PROJECT_NAME}"
        NAMESPACE ${PROJECT_NAME}::
)
