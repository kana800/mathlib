cmake_minimum_required(VERSION 3.2)


set(HEADERS 
	"coordinate.h"
)

set(TESTING 1)

add_library(coord ${HEADERS} "coordinate.c")

if (TESTING)
add_executable(coordtest ${HEADERS} "coordinate.c")
endif()


set_target_properties(
	coord PROPERTIES 
	LINKER_LANGUAGE C
)

