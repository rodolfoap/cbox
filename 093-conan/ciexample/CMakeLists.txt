cmake_minimum_required(VERSION 3.16)

project(HelloWorld)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wunused-value -Wuninitialized -Werror -Wreturn-local-addr -Werror=return-local-addr -fPIC)

execute_process(COMMAND cat VERSION COMMAND cut -f2 -d= WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE VERSION)
message("Library VERSION is: ${VERSION}")

# Don't run conan install within conan create!
option(IS_BUILDING_FROM_CONAN "Is running from conan create?" OFF)
if (NOT ${IS_BUILDING_FROM_CONAN})
  execute_process(
    COMMAND conan install "${CMAKE_CURRENT_SOURCE_DIR}" --build missing
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
endif()

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(nlohmann_json REQUIRED)

add_subdirectory(src)

install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Config
  DESTINATION lib
)

install(EXPORT ${PROJECT_NAME}Config
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
  NAMESPACE ${PROJECT_NAME}::
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake VERSION ${VERSION} COMPATIBILITY AnyNewerVersion)
