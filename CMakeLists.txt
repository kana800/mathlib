cmake_minimum_required(VERSION 3.2)

project(mathlib C)

# adding the grapher library
add_subdirectory(lineargrapher)

add_executable(mathlib "demo/demograph.c")


target_link_libraries(mathlib 
	PRIVATE LINEARGRAPHER)
target_include_directories(mathlib
	PRIVATE LINEARGRAPHER)
