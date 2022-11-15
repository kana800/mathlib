cmake_minimum_required (VERSION 3.8)

project(MathLibTest)


set(LinearTest 1)

if (LinearTest)
	set(SOURCES 
		"LinearGrapherTest.c"
	)
endif()

add_executable(MathLibTest ${SOURCES})

target_include_directories(MathLibTest
	PRIVATE LINEARGRAPHER check
)

target_link_libraries(MathLibTest
	PRIVATE LINEARGRAPHER check
)
