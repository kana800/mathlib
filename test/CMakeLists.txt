cmake_minimum_required (VERSION 3.8)

project(MathLibTest)

set(SOURCES 
	"LinearGrapherTest.c"
)

add_executable(MathLibTest ${SOURCES})

target_link_libraries(MathLibTest PRIVATE
	LINEARGRAPHER
)
