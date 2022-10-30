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

/*
global structure that holds all the coordinates
data:
	- size  -> size of the container
	- coord_t* arr -> an array pointer for the coordinate
	structure; (assigned at intializeContainer)
*/
typedef struct glbCoordinateContainer {
	int size;
	coord_t* arr;
} glbCoordContainer;

/*----Coordinate----*/
/*create a coordinate*/
coord_t* createCoordinate(int x, int y);
/*delete a coordinate*/
bool deleteCoordinate(coord_t* cptr);


#endif // !COORDINATE_H
