/*coordinate.h
	polar and cartesian coordinate system 
HISTORY
	v 0.10 First Public Release

USAGE
	

*/
#ifndef ML_COORDINATE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// coordinate structure
typedef struct coordinate {
	int x;
	int y;
} coord;

// add multiple coordinates together
coord c_addcoordinate(
	coord c1, coord c2, ...) {
	/*summary: add multiple coordiantes together
	args: coord
	return:
		coord
	*/
	va_list ptr;
	va_start(ptr, c1);

	coord temp = {.x = 0, .y = 0};



	va_end(ptr);
}





#endif // !ML_COORDINATE
