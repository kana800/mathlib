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

#endif // !ML_COORDINATE
