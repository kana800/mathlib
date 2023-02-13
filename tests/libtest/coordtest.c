/*test cases for the coordinate library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "../../lib/coord/coord.h"

int main(int argc, char* argv[]){

	cartesiancoord* temp1 = c_createcartesiancoordinate(5,5);
	cartesiancoord* temp2 = c_createcartesiancoordinate(5,5);
	
	assert(temp1->x == 5);
	assert(temp1->y == 5);

	cartesiancoord* temp3 = addcartesiancoordinate(2, temp1, temp2);
	assert(temp3->x == 10);
	assert(temp3->y == 10);

	cartesiancoord* temp4 = subcartesiancoordinate(2, temp1, temp2);
	assert(temp4->x == 0);
	assert(temp4->y == 0);


	cartesiancoord* temp5 = multcartesiancoordinate(2, temp1, temp2);
	assert(temp5->x == 25);
	assert(temp5->y == 25);

	cartesiancoord* temp6 = divcartesiancoordinate(2, temp1, temp2);
	assert(temp6->x == 1);
	assert(temp6->y == 1);

	// testing out multiple inputs
	cartesiancoord* temp7 = addcartesiancoordinate(3, temp1, temp2, temp5);
	assert(temp7->x == 35);
	assert(temp7->y == 35);

	cartesiancoord* midpoint = c_findmidpoint(temp5, temp1);
	assert(midpoint->x == 15);
	assert(midpoint->y == 15);

	// freeing
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(temp5);
	free(temp6);
	free(temp7);
	free(midpoint);
}
