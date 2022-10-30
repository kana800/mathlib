cmake_minimum_required(VERSION 3.2)

project(mathlib C)

# adding the grapher library
add_subdirectory(grapher)

add_executable(mathlib "demo/demograph.c")


target_link_libraries(mathlib 
	PRIVATE GRAPHER)
target_include_directories(mathlib
	PRIVATE GRAPHER)
