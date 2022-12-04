cmake_minimum_required(VERSION 3.2)

set(HEADERS 
	"coordinate.h"
)

add_library(coord ${HEADERS} "coordinate.c")

set_target_properties(
	coord PROPERTIES 
	LINKER_LANGUAGE C
)

