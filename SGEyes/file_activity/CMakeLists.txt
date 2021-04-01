cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

add_library(file_activity
	STATIC
		directory_watcher_mgr.hpp
		directory_watcher_mgr.cpp
)

target_include_directories(file_activity 
	PRIVATE 
		${SG_FMT_INC_DIR}
		${SG_SAIGONLIB_INC_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}
)

