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

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(include)
if (BUILD_TESTS)
        enable_testing()
        add_subdirectory(test)
endif()

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_SYSTEM_NAME "linux")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>=2.4)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "rodolfoap@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Helloworld library-dependent app")
include(CPack)
