cmake_minimum_required(VERSION 3.2)


set(SRC 
	"grapher.c"
 "coordinate.c" "coordcontainer.c")

set(HEADERS 
	"grapher.h"
 "coordinate.h" "coordcontainer.h")


add_library(GRAPHER ${SRC} ${HEADERS})
