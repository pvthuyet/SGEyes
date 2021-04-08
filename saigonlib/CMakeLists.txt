cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Local variable
set(LOCAL_VLD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vld)
set(LOCAL_FMT_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fmt_7_1_3/include)
set(LOCAL_GSL_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gsl/include)
set(LOCAL_SAIGONLIB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LOCAL_BOOST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_75_0)
set(LOCAL_NLOHMANN_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann_3_7_3)

# Parent variable
set(SG_VLD_DIR ${LOCAL_VLD_DIR} PARENT_SCOPE)
set(SG_FMT_INC_DIR ${LOCAL_FMT_INC_DIR} PARENT_SCOPE)
set(SG_GSL_INC_DIR ${LOCAL_GSL_INC_DIR} PARENT_SCOPE)
set(SG_SAIGONLIB_INC_DIR ${LOCAL_SAIGONLIB_INC_DIR} PARENT_SCOPE)
set(SG_BOOST_INC_DIR ${LOCAL_BOOST_INC_DIR} PARENT_SCOPE)
set(SG_NLOHMANN_INC_DIR ${LOCAL_NLOHMANN_INC_DIR} PARENT_SCOPE)

add_library(saigonlib STATIC
	"include/timer.hpp"
	"src/timer.cpp"
	 "include/string_utils.hpp" "src/string_utils.cpp")

add_subdirectory(fmt_7_1_3)

set_property(TARGET saigonlib PROPERTY CXX_STANDARD 20)

target_include_directories(saigonlib PRIVATE
	${LOCAL_FMT_INC_DIR}
	${LOCAL_GSL_INC_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(saigonlib PRIVATE fmt)

#############################################################################
# Test project
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
if(ENABLE_UNIT_TESTS)
  # all the remaining CMake code will be placed here
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	# Prevent GoogleTest from overriding our compiler/linker options
	# when building with Visual Studio
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	# Prevent GoogleTest from using PThreads
	set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

	# adds the targers: gtest, gtest_main, gmock, gmock_main
	add_subdirectory(
		${googletest_SOURCE_DIR}
		${googletest_BINARY_DIR}
    )

	# Silence std::tr1 warning on MSVC
	if(MSVC)
		foreach(_tgt gtest gtest_main gmock gmock_main)
			target_compile_definitions(${_tgt}
				PRIVATE
					"_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
				)
		endforeach()
	endif()
endif()

# Test test_circle_map2
add_executable(test_circle_map2 "")
target_sources(test_circle_map2 PRIVATE
    "test/test_circle_map2.cpp"
   "include/string_utils.hpp" "src/string_utils.cpp")

target_include_directories(test_circle_map2 PRIVATE
	${LOCAL_BOOST_INC_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
	)

target_link_libraries(test_circle_map2 PRIVATE
    gtest_main
	)

enable_testing()

add_test(
  NAME google_test
  COMMAND $<TARGET_FILE:test_circle_map2>
  )

################################################################
## boost exmaple
add_executable(message_queue1 
	test/test_message_queue1.cpp
	)
target_include_directories(message_queue1 PRIVATE
	${LOCAL_BOOST_INC_DIR}
	)

add_executable(message_queue2
	test/test_message_queue2.cpp
	)
target_include_directories(message_queue2 PRIVATE
	${LOCAL_BOOST_INC_DIR}
	)