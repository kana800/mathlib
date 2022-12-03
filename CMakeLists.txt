cmake_minimum_required(VERSION 3.8)

project(mathlib C)

set(TESTING 1)

# adding the grapher library
#add_subdirectory(lineargrapher)

# build with testing features for 
# mathlib
if (TESTING)
	add_subdirectory(external/check)
	# adding the test directories
	add_subdirectory(tests)
endif()

add_subdirectory(lib)

#add_executable(mathlib "demo/demograph.c" "lib/coordinate.h")

#target_link_libraries(mathlib 
#	PRIVATE LINEARGRAPHER)
#target_include_directories(mathlib
#	PRIVATE LINEARGRAPHER)

