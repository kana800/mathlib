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
	/*summary: add multiple coordiantes together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	return:
		coord
	*/

	// adding the default two arguments
	// have a separate function for this later
	coord temp = 
		{ .x = c1.x + c2.x, .y = c1.y + c2.y };
	count -= 2;

	va_list ptr;
	va_start(ptr, c2);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
		temp = { .x = temp.x + test.x, .y = temp.y + test.y };
		printf("test coord (%d,%d)", test.x, test.y);
	}
	va_end(ptr);

	return temp;
}





#endif // !ML_COORDINATE
