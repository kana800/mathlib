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

// forward declaration
coord addcoordinate(int count, ...);

#define VA_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)	N
#define VA_NUM_ARGS(...)	VA_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define c_addcoordinate(...) addcoordinate(VA_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)

// create a coordinate in the heap
coord* c_createcoordinate(int x, int y) {
	/*summary: create a coordinate structure in the heap
	args:
		int x -> x coordinate
		int y -> y coordinate
	*/
	coord* temp = (coord*)malloc(sizeof(coord));
	temp->x = x;
	temp->y = y;
}

// add multiple coordinates together
coord addcoordinate(int count, ...) {
	/*summary: add multiple coordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	return:
		coord
	*/

	coord temp = { .x = 0, .y = 0 };

	printf("detected count is %d \n", count);
	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
		printf("coordinate %d: (%d,%d) \n", count, test.x, test.y);
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

// divide multiple coordinates together
coord c_divcoordinate(
	int count, coord c1, coord c2, ...) {
	/*summary: divide multiple coordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	---
		ans = c1 / c2
		ans = c1 / c2 / c3 / c4 / c5
		            ^
					START
	---
	return:
		coord
	*/

	coord temp = { .x = 0,.y = 0 };
	// cant divide by zero; so we
	// are skipping these values
	if ((c2.x != 0) || (c2.y != 0)) {
		temp.x = c1.x / c2.x;
		temp.y = c1.y / c2.y;
	}

	/*accounting for the c1 and c2 coordinates*/
	count -= 2;

	va_list ptr;
	va_start(ptr, c2);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);

		if ((temp.x != 0) || (temp.y != 0)) {
			temp.x /= test.x;
			temp.y /= test.y;
		}
		else {
			continue;
		}
		
	}
	va_end(ptr);

	return temp;
}

// multiple multiple coordinates together
coord c_multcoordinate(
	int count, coord c1, coord c2, ...) {
	/*summary: multiply multiple coordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	---
		ans = c1 * c2
		ans = c1 * c2 * c3 * c4 * c5
		            ^
					START
	---
	return:
		coord
	*/

	coord temp = { .x = c1.x * c2.x,.y = c1.y * c2.y };

	/*accounting for the c1 and c2 coordinates*/
	count -= 2;

	va_list ptr;
	va_start(ptr, c2);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
		temp.x *= test.x;
		temp.y *= test.y;
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
