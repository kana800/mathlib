#include "coordinate.h"

coord_t* createCoordinate(int xa, int ya) {
	/*summary: allocates memory and returns pointer
	args:
		int xa -> x coordinate
		int ya -> y coordinate
	*/
	coord_t* c = malloc(sizeof(coord_t));
	c->x = xa;
	c->y = ya;
	printf("(coordinate) Memory Created: %p\n", c);
	return c;
};


bool deleteCoordinate(coord_t* cptr) {
	/*summary: frees the memory from of the coordinate*/
	printf("(coordinate) Memory Freed: %p\n", cptr);
	free(cptr);
	return true;
}