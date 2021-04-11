cmake_minimum_required(VERSION 3.10)
execute_process(WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND sed "/^VERSION=/s:^.*=::" VERSION
	COMMAND tr -d '\n'
	OUTPUT_VARIABLE VERSION
)
project(helloworld VERSION ${VERSION})
message("Library VERSION is: ${VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)

execute_process(COMMAND conan install "${CMAKE_CURRENT_SOURCE_DIR}" --build missing WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(nlohmann_json REQUIRED)

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(include)
if (BUILD_TESTS)
        enable_testing()
        add_subdirectory(test)
endif()
add_custom_target(${PROJECT_NAME}_doc ALL COMMAND ./build-doc.sh WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMENT "Generating API documentation with Doxygen")

# /usr/include/nlohmann/json.hpp
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/nlohmann_json/include/nlohmann/json.hpp DESTINATION include/nlohmann/)

# /usr/share/doc/helloworld/README.md
install(FILES ${PROJECT_SOURCE_DIR}/README.md DESTINATION share/doc/${PROJECT_NAME}/)

# /usr/share/doc/helloworld/html/index.html et.al.
install(DIRECTORY ${PROJECT_SOURCE_DIR}/doc/html/ DESTINATION share/doc/${PROJECT_NAME}/html)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_SYSTEM_NAME "linux")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>=2.4)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "rodolfoap@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Helloworld library-dependent app")
include(CPack)
