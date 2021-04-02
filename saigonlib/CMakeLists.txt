cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

set(SG_FMT_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fmt_7_1_3/include PARENT_SCOPE)
set(SG_GSL_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gsl/include PARENT_SCOPE)
set(SG_SAIGONLIB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
set(SG_BOOST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_75_0 PARENT_SCOPE)

add_library(saigonlib STATIC
	include/task_timer.hpp
	src/task_timer.cpp)

add_subdirectory(fmt_7_1_3)

set_property(TARGET saigonlib PROPERTY CXX_STANDARD 20)

target_include_directories(saigonlib PRIVATE
	${SG_FMT_INC_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(saigonlib PRIVATE fmt)
