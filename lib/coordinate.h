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

/*
obtained from stackoverflow; 
*/
#define PP_NARG(...) \
         PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) \
         PP_128TH_ARG(__VA_ARGS__)
#define PP_128TH_ARG( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
         _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
         _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
         _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
         _101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
         _111,_112,_113,_114,_115,_116,_117,_118,_119,_120, \
         _121,_122,_123,_124,_125,_126,_127,N,...) N
#define PP_RSEQ_N() \
         127,126,125,124,123,122,121,120, \
         119,118,117,116,115,114,113,112,111,110, \
         109,108,107,106,105,104,103,102,101,100, \
         99,98,97,96,95,94,93,92,91,90, \
         89,88,87,86,85,84,83,82,81,80, \
         79,78,77,76,75,74,73,72,71,70, \
         69,68,67,66,65,64,63,62,61,60, \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

coord _c_addcoordinate(int count, coord c1, coord c2, ...);
#define c_addcoordinate(...) _c_addcoordinate(PP_NARG(__VA_ARGS__), __VA_ARGS__)

// coordinate structure
typedef struct coordinate {
	int x;
	int y;
} coord;

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
coord _c_addcoordinate(
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
