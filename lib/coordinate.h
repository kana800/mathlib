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

#define DEBUG 1

// coordinate structure
typedef struct coordinate {
	int x;
	int y;
} coord;

// forward declaration
coord addcoordinate(int count, ...);
coord subcoordinate(int count, ...);
coord divcoordinate(int count, ...);
coord multcoordinate(int count, ...);


#ifndef _MSC_VER

#define VA_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)	N
#define VA_NUM_ARGS(...)	VA_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
// have to test this in a gcc compiler
#define c_addcoordinate(...) addcoordinate(VA_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)

#endif

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

	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
#ifdef DEBUG
		printf("addcoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
		temp.x += test.x;
		temp.y += test.y;
	}
	va_end(ptr);

	return temp;
}

// subtract multiple coordinates together
coord subcoordinate(int count, ...) {
	/*summary: subtract multiple coordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		coord
	return:
		coord
	*/


	va_list ptr;
	va_start(ptr, count);

	coord test = va_arg(ptr, coord);
	coord temp = { .x = test.x, .y = test.y };

	for (int i = 1; i < count; i++) {
		test = va_arg(ptr, coord);
#ifdef DEBUG
		printf("subcoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
		temp.x -= test.x;
		temp.y -= test.y;
	}
	va_end(ptr);

	return temp;
}

// divide multiple coordinates together
coord divcoordinate(int count, ...) {
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

	va_list ptr;
	va_start(ptr, count);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
#ifdef DEBUG
		printf("divcoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
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
coord multcoordinate(int count, ...) {
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

	coord temp = { .x = 1,.y = 1 };

	va_list ptr;
	va_start(ptr, count);

	for (int i = 0; i < count; i++) {
		coord test = va_arg(ptr, coord);
#ifdef DEBUG
		printf("multcoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
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
