/*coordinate.h
	polar and cartesian coordinate system 
HISTORY
	v 0.10 First Public Release
USAGE

*/
#ifndef ML_COORDINATE
#define ML_COORDINATE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../trig/trig.h"

#define DEBUG 0

// coordinate structure
typedef struct coordinate {
	double x; // x value
	double y; // y value
} cartesiancoord;

typedef struct polarcoordinate {
	double r; // radius
	double theta; // angle
} polarcoord;

// forward declaration cartesian functions
cartesiancoord* c_createcartesiancoordinate(double x, double y);
cartesiancoord* addcartesiancoordinate(int count, ...);
cartesiancoord* subcartesiancoordinate(int count, ...);
cartesiancoord* divcartesiancoordinate(int count, ...);
cartesiancoord* multcartesiancoordinate(int count, ...);
cartesiancoord* c_findmidpoint(
		cartesiancoord* c1, cartesiancoord* c2);

// forward declaration of polar functions
polarcoord* c_createpolarcoordinate(double r, double theta);
cartesiancoord* convertpolartocartesian(polarcoord* coord);

#endif // !ML_COORDINATE
