cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

add_library(file_activity STATIC
	watcher/directory_watcher_base.hpp
	watcher/directory_watcher_base.cpp
	watcher/file_notify_info.hpp
	watcher/file_notify_info.cpp
	watcher/idirectory_watcher.hpp
	watcher/iobserver.hpp
	watcher/irequest.hpp
	watcher/observer_impl.hpp
	watcher/observer_impl.cpp
	watcher/request_impl.hpp
	watcher/request_impl.cpp
	watcher/unnecessary_directory.hpp
	watcher/unnecessary_directory.cpp
	watcher/watching_setting.hpp
	watcher/watching_setting.cpp
	directory_watcher_mgr.hpp
	directory_watcher_mgr.cpp
)

target_include_directories(file_activity 
	PRIVATE 
		${SG_GSL_INC_DIR}
		${SG_SPDLOG_INC_DIR}
		${SG_LOGGER_INC_DIR}
		${SG_SAIGONLIB_INC_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}
)

