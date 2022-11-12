#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
coordinate structure
data:
	- x -> x coordinate
	- y -> y coordinate
*/
typedef struct Coordinate {
	int x;
	int y;
} coord_t;

/*----Coordinate----*/
/*create a coordinate*/
coord_t* createCoordinate(int x, int y);
/*delete a coordinate*/
bool deleteCoordinate(coord_t* cptr);


#endif // !COORDINATE_H
