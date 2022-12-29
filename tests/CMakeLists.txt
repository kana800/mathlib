cmake_minimum_required (VERSION 3.8)

project(MathLibTest)

set(LinearTest 0)
set(LibTest 1)

# src files for modules
if (LinearTest)
	set(SOURCES 
		"LinearGrapherTest.c"
	)
endif()

# src files for libraries
if (LibTest)
	add_subdirectory(libtest)
endif()

add_executable(MathLibTest "main.c" ${HEADERS})

target_include_directories(MathLibTest
	PRIVATE coord matrix check
)

target_link_libraries(MathLibTest
	PRIVATE coord matrix check
)

target_link_libraries(MathLibTest
	PRIVATE coord matrix check
)
