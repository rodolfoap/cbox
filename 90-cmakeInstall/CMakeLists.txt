cmake_minimum_required(VERSION 3.10)
project(helloworld)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# --- BOTH --------------------------------------------------------------------------------
# Install configuration is: "Release"
set(CMAKE_BUILD_TYPE Release)

# --- LIBRARY -----------------------------------------------------------------------------
add_library(helloworld SHARED lib_helloworld.cpp) 	#	[1]
target_include_directories(helloworld PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Will include the header in the installers 			[2]
set_target_properties(helloworld PROPERTIES PUBLIC_HEADER include/helloworld.hpp)

install(TARGETS helloworld
	# Will install /usr/local/lib/libhelloworld.so 		[1]
	LIBRARY DESTINATION lib
	# Will install /usr/local/include/helloworld.hpp 	[2]
        PUBLIC_HEADER DESTINATION include
)

# --- BINARY ------------------------------------------------------------------------------
add_executable(helloworld-bin app_helloworld.cpp)
target_link_libraries(helloworld-bin helloworld)

# Target has a different name, otherwise names would clash:
# 	target_link_libraries(helloworld helloworld)'
# this is only an issue of this example, is not generic
set_target_properties(helloworld-bin PROPERTIES OUTPUT_NAME helloworld)
# this avoids complains: '-- Set runtime path of "/usr/local/bin/helloworld" to ""'
set_target_properties(helloworld-bin PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)

install(TARGETS helloworld-bin
	RUNTIME DESTINATION bin
)
