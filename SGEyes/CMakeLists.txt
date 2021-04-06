# CMakeList.txt : CMake project for CMakeProject2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project(SGEye LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(SGEyes 
	 "main.cpp" 
	 "the_app.cpp" 
	 "the_app.hpp" 
	 "logger/logger.hpp"
	 "logger/logger.cpp"
	 "config/configuration.hpp"
	 "config/configuration.cpp"
	 )

#set_property(TARGET SGEyes PROPERTY CXX_STANDARD 20)

# Dealing with platform-dependent source code
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(SGEyes PUBLIC "IS_LINUX")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(SGEyes PUBLIC "IS_MACOS")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(SGEyes PUBLIC "IS_WINDOWS")
endif()

# Dealing with compiler-dependent source code
message("CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
    target_compile_definitions(SGEyes PUBLIC "IS_INTEL_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_compile_definitions(SGEyes PUBLIC "IS_GNU_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES PGI)
    target_compile_definitions(SGEyes PUBLIC "IS_PGI_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES XL)
    target_compile_definitions(SGEyes PUBLIC "IS_XL_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
	target_compile_definitions(SGEyes PUBLIC "IS_MSVC_CXX_COMPILER")
endif()

# Discovering the host processor architecture
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  target_compile_definitions(SGEyes PUBLIC "IS_64_BIT_ARCH")
  message(STATUS "Target is 64 bits")
else()
  target_compile_definitions(SGEyes PUBLIC "IS_32_BIT_ARCH")
  message(STATUS "Target is 32 bits")
endif()

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
  message(STATUS "i386 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
  message(STATUS "i686 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
  message(STATUS "x86_64 architecture detected")
else()
  message(STATUS "host processor architecture is unknown")
endif()

target_compile_definitions(SGEyes
  PUBLIC "ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}"
  )

# Setting the standard for the language
set_target_properties(SGEyes
	PROPERTIES
		CXX_STANDARD			20
		CXX_EXTENSIONS			OFF
		CXX_STANDARD_REQUIRED	ON
)

# Set CMAKE_BUILD_TYPE
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
	target_compile_definitions(SGEyes PUBLIC "IS_DEBUG")
endif()

set(COMPILER_FLAGS)
set(COMPILER_FLAGS_DEBUG)
set(COMPILER_FLAGS_RELEASE)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
  #list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Wall" "-O0" "-fsanitize=address")
  list(APPEND CXX_FLAGS "-Wall" "-O0")
  list(APPEND CXX_FLAGS_DEBUG "-Wsuggest-final-types" "-Wsuggest-final-methods" "-Wsuggest-override")
  list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)  
  #list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics")
  list(APPEND CXX_FLAGS "-Wall" "-pendantic" "-fcolor-diagnostics")
  list(APPEND CXX_FLAGS_DEBUG "-Wdocumentation")
  list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif()

# Visual leak detector => work only MSVC
if(CMAKE_BUILD_TYPE MATCHES Debug)  
	message(STATUS "Enabling Visual Leak Detector")
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		find_library(VLD vld HINTS "${SG_VLD_DIR}/lib/Win64")
	else()
		find_library(VLD vld HINTS "${SG_VLD_DIR}/lib/Win32")
	endif()
	find_path(VLD_INC_DIR vld.h HINTS "${SG_VLD_DIR}/include")
	message(STATUS "VLD: ${VLD}")
	message(STATUS "VLD_INC_DIR: ${VLD_INC_DIR}")
	target_include_directories(SGEyes PRIVATE ${VLD_INC_DIR})
	target_link_libraries(SGEyes PRIVATE ${VLD})
endif()

target_compile_options(SGEyes
  PRIVATE
    ${CXX_FLAGS}
    "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
    "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>"
 )

# spdlog
set(SG_SPDLOG_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/logger/spdlog_1_8_5/include)
set(SG_LOGGER_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/logger)

target_include_directories(SGEyes 
	PRIVATE 
		${SG_NLOHMANN_INC_DIR}
		${SG_SPDLOG_INC_DIR}
		${SG_LOGGER_INC_DIR}
		${SG_SAIGONLIB_INC_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}
)

# File activity
add_subdirectory (file_activity)

# Link library
target_link_libraries(SGEyes PRIVATE saigonlib)
target_link_libraries(SGEyes PRIVATE file_activity)

# copy config.json to outdir
add_custom_command(TARGET SGEyes POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/config/config.json" ${CMAKE_CURRENT_BINARY_DIR}
)

# TODO: Add tests and install targets if needed.