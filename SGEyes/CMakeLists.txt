# CMakeList.txt : CMake project for CMakeProject2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

# fmtlib
set(FMTLIB_DIR "../../saigon-library/saigonlib/3rd_party/fmtlib")
message(STATIC "src: ${FMTLIB_DIR}/src/format.cc")

# Add include directory
list(APPEND SAIGON_LIB_INCLUDES 
	"../../saigon-library/saigonlib/include"
	"${FMTLIB_DIR}/include"
	)


# Add source to this project's executable.
add_executable (SGEyes "main.cpp" "the_app.cpp" "the_app.hpp" "${FMTLIB_DIR}/src/format.cc" "${FMTLIB_DIR}/src/os.cc")

target_include_directories(SGEyes PUBLIC ${SAIGON_LIB_INCLUDES})

# TODO: Add tests and install targets if needed.