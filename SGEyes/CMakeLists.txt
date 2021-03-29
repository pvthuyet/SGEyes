# CMakeList.txt : CMake project for CMakeProject2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

add_executable(SGEyes "main.cpp" "the_app.cpp" "the_app.hpp")

target_include_directories(SGEyes PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/fmt/${FMT_INC_DIR}
	)
target_link_libraries(SGEyes PRIVATE fmt)

# TODO: Add tests and install targets if needed.