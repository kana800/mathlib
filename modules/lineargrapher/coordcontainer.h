/*
This file contains an implementation for the coordinate container;
The container will hold the data and pointer to the next container,

There will be static global variables to keep in track of the head
and many more stuff;
*/
#ifndef COORDCONTAINER_H
#define COORDCONTAINER_H

#include <stdio.h>
#include <stdlib.h>

#include "coordinate.h"

/*
coord container is a linked list;
data:
	- data -> pointer to the coord_t struct
	- next -> pointer to the next container
*/
typedef struct CoordContainer {
	coord_t* data;
	struct CoordContainer* next;
} coordcontainer_t;

/*
static pointer to the start of 
the coord container
*/
static coordcontainer_t* head = NULL;

/*create and add a coordinate to the container*/
coordcontainer_t* CreateCoordinateContainer(int x, int y);
/*delete the coordinate container from the container*/
bool DeleteCoordinateContainer(coordcontainer_t* cptr);
/*prints the coordinate container linked list*/
void PrintCoordinateContainer();
/*prints the coordintate*/
void PrintCoordinate(coord_t* cptr);


#endif // !COORDCONTAINER_H
