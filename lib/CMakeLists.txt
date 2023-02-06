# cmakefile for lib
cmake_minimum_required(VERSION 3.2)

# coordinates 
set(COORD_HEADERS 
	"coordinate.h"
)
set(COORD_SRC
	"coordinate.c"
)

# trigonometric functions
set(TRIG_HEADERS
	"trig.h"
)
set(TRIG_SRC
	"trig.c"
)

# matrices
set(MAT_HEADERS
	"matrix.h"
)

set(MAT_SRC
	"matrix.c"
)

add_library(coord ${COORD_HEADERS} ${COORD_SRC})
add_library(trig ${TRIG_HEADERS} ${TRIG_SRC})
add_library(matrix ${MAT_HEADERS} ${MAT_SRC})

set_target_properties(
	coord matrix PROPERTIES 
	LINKER_LANGUAGE C
)