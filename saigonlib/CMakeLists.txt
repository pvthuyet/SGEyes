cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

add_library(saigonlib STATIC
	include/task_timer.hpp
	src/task_timer.cpp)

set_property(TARGET saigonlib PROPERTY CXX_STANDARD 20)

target_include_directories(saigonlib PRIVATE
	${SG_FMT_INC_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(saigonlib PRIVATE fmt)