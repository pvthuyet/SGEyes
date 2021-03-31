cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

add_library(file_activity
	STATIC
		directory_watcher_mgr.hpp
		directory_watcher_mgr.cpp
)

target_include_directories(file_activity 
	PRIVATE 
		${PROJECT_SOURCE_DIR}/saigonlib/include
		${CMAKE_CURRENT_SOURCE_DIR}
		${PROJECT_SOURCE_DIR}/fmt/${FMT_INC_DIR}
)