cmake_minimum_required(VERSION 3.2)


set(COORD_HEADERS 
	"coordinate.h"
)
set(COORD_SRC
	"coordinate.c"
)

add_library(coord ${COORD_HEADERS} ${COORD_SRC})

set_target_properties(
	coord PROPERTIES 
	LINKER_LANGUAGE C
)

