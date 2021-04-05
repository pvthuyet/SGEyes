cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Local variable
set(LOCAL_FMT_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fmt_7_1_3/include)
set(LOCAL_GSL_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gsl/include)
set(LOCAL_SAIGONLIB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LOCAL_BOOST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_75_0)

# Parent variable
set(SG_FMT_INC_DIR ${LOCAL_FMT_INC_DIR} PARENT_SCOPE)
set(SG_GSL_INC_DIR ${LOCAL_GSL_INC_DIR} PARENT_SCOPE)
set(SG_SAIGONLIB_INC_DIR ${LOCAL_SAIGONLIB_INC_DIR} PARENT_SCOPE)
set(SG_BOOST_INC_DIR ${LOCAL_BOOST_INC_DIR} PARENT_SCOPE)

add_library(saigonlib STATIC
	"include/task_timer.hpp"
	"src/task_timer.cpp"
	)

add_subdirectory(fmt_7_1_3)

set_property(TARGET saigonlib PROPERTY CXX_STANDARD 20)

target_include_directories(saigonlib PRIVATE
	${SG_FMT_INC_DIR}
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
  )

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