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
	int count, coord c1, coord c2, ...) {
	/*summary: add multiple coordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	return:
		coord
	*/

	coord temp = 
		{ .x = c1.x + c2.x, .y = c1.y + c2.y };
	/*accounting for the c1 and c2 coordinates*/
	count -= 2;

	va_list ptr;
	va_start(ptr, c2);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
		temp.x += test.x;
		temp.y += test.y;
	}
	va_end(ptr);

	return temp;
}


// subtract multiple coordinates together
coord c_subcoordinate(
	int count, coord c1, coord c2, ...) {
	/*summary: subtract multiple coordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	return:
		coord
	*/

	coord temp = 
		{ .x = c1.x - c2.x, .y = c1.y - c2.y };
	/*accounting for the c1 and c2 coordinates*/
	count -= 2;

	va_list ptr;
	va_start(ptr, c2);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
		temp.x -= test.x;
		temp.y -= test.y;
	}
	va_end(ptr);

	return temp;
}

// find midpoint between two coordinates
coord c_findmidpoint(coord c1, coord c2) {
	/*summary: find midpoint between two coordinates
	args:
		coord
	return:
		coord
	*/
	coord temp = { .x = 0, .y = 0 };

	temp.x = (c1.x + c2.x) / 2;
	temp.y = (c1.y + c2.y) / 2;

	return temp;
}

#endif // !ML_COORDINATE
