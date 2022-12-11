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
	int x; // x value
	int y; // y value
} cartesiancoord;

typedef struct polarcoordinate {
	float r; // radius
	float theta; // angle
} polarcoord;

// forward declaration cartesian functions

cartesiancoord addcartesiancoordinate(int count, ...);
cartesiancoord subcartesiancoordinate(int count, ...);
cartesiancoord divcartesiancoordinate(int count, ...);
cartesiancoord multcartesiancoordinate(int count, ...);

// forward declaration of polar functions

polarcoord addpolarcoordinate(int count, ...);
polarcoord subpolarcoordinate(int count, ...);
polarcoord divpolarcoordinate(int count, ...);
polarcoord multpolarcoordinate(int count, ...);

#ifndef _MSC_VER

#define VA_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)	N
#define VA_NUM_ARGS(...)	VA_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
// have to test this in a gcc compiler
#define c_addcoordinate(...) addcoordinate(VA_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)

#endif

// create a cartesian coordinate in the heap
cartesiancoord* c_createcartesiancoordinate(int x, int y) {
	/*summary: create a cartesiancoordinate structure in the heap
	args:
		int x -> x cartesiancoordinate
		int y -> y cartesiancoordinate
	*/
	cartesiancoord* temp = \
		(cartesiancoord*)malloc(sizeof(cartesiancoord));
	temp->x = x;
	temp->y = y;
}

// create a polar coordinate in the heap
polarcoord* c_createpolarcoordinate(int r, int theta) {
	/*summary: create a polarcoordinate structure in the heap
	args:
		int r -> r polarcoordinate
		int theta -> theta polarcoordinate
	*/
	polarcoord* temp = \
		(polarcoord*)malloc(sizeof(polarcoord));
	temp->r = r;
	temp->theta = theta;
}

// add multiple coordinates together
cartesiancoord addcartesiancoordinate(int count, ...) {
	/*summary: add multiple cartesiancoordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		cartesiancoord
	return:
		cartesiancoord
	*/

	cartesiancoord temp = { .x = 0, .y = 0 };

	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++) {
		cartesiancoord test = va_arg(ptr, cartesiancoord);
#ifdef DEBUG
		printf("addcartesiancoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
		temp.x += test.x;
		temp.y += test.y;
	}
	va_end(ptr);

	return temp;
}

// subtract multiple cartesiancoordinates together
cartesiancoord subcartesiancoordinate(int count, ...) {
	/*summary: subtract multiple cartesiancoordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		cartesiancoord
	return:
		cartesiancoord
	*/


	va_list ptr;
	va_start(ptr, count);

	cartesiancoord test = va_arg(ptr, cartesiancoord);
	cartesiancoord temp = { .x = test.x, .y = test.y };

	for (int i = 1; i < count; i++) {
		test = va_arg(ptr, cartesiancoord);
#ifdef DEBUG
		printf("subcartesiancoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
		temp.x -= test.x;
		temp.y -= test.y;
	}
	va_end(ptr);

	return temp;
}

// divide multiple cartesiancoordinates together
cartesiancoord divcartesiancoordinate(int count, ...) {
	/*summary: divide multiple cartesiancoordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		cartesiancoord
	---
		ans = c1 / c2
		ans = c1 / c2 / c3 / c4 / c5
		            ^
					START
	---
	return:
		cartesiancoord
	*/

	cartesiancoord temp = { .x = 0,.y = 0 };

	va_list ptr;
	va_start(ptr, count);

	for (int i = 0; i < count; i++) {
		cartesiancoord test = va_arg(ptr, cartesiancoord);
#ifdef DEBUG
		printf("divcartesiancoordinate %d: (%d,%d) \n", i, test.x, test.y);
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

// multiple multiple cartesiancoordinates together
cartesiancoord multcartesiancoordinate(int count, ...) {
	/*summary: multiply multiple cartesiancoordinates together
	args:
		int count -> sentinel value;
			number of arguments passed
		cartesiancoord
	---
		ans = c1 * c2
		ans = c1 * c2 * c3 * c4 * c5
		            ^
					START
	---
	return:
		cartesiancoord
	*/

	cartesiancoord temp = { .x = 1,.y = 1 };

	va_list ptr;
	va_start(ptr, count);

	for (int i = 0; i < count; i++) {
		cartesiancoord test = va_arg(ptr, cartesiancoord);
#ifdef DEBUG
		printf("multcartesiancoordinate %d: (%d,%d) \n", i, test.x, test.y);
#endif
		temp.x *= test.x;
		temp.y *= test.y;
	}
	va_end(ptr);

	return temp;
}

// find midpoint between two cartesiancoordinates
cartesiancoord c_findmidpoint(cartesiancoord c1, cartesiancoord c2) {
	/*summary: find midpoint between two cartesiancoordinates
	args:
		cartesiancoord
	return:
		cartesiancoord
	*/
	cartesiancoord temp = { .x = 0, .y = 0 };

	temp.x = (c1.x + c2.x) / 2;
	temp.y = (c1.y + c2.y) / 2;

	return temp;
}

#endif // !ML_COORDINATE
