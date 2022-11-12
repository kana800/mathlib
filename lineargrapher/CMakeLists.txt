cmake_minimum_required(VERSION 3.2)


set(SRC 
	"lineargrapher.c"
	"coordinate.c" 
	"coordcontainer.c")

set(HEADERS 
	"lineargrapher.h"
	"coordinate.h"
	"coordcontainer.h")


add_library(LINEARGRAPHER ${SRC} ${HEADERS})

