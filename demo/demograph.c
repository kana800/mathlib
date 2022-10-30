#include <stdio.h>
#include <stddef.h>

#include "coordcontainer.h"

int main(int argc, char* argv[]) {

	// creating coordinates
	coordcontainer_t* t1 = CreateCoordinateContainer(5, 10);
	coordcontainer_t* t2 = CreateCoordinateContainer(2, 4);
	coordcontainer_t* t3 = CreateCoordinateContainer(22, 41);
	coordcontainer_t* t4 = CreateCoordinateContainer(24, 42);

	PrintCoordinateContainer();


	bool state = DeleteCoordinateContainer(t4);
	PrintCoordinateContainer();

	return 0;
}