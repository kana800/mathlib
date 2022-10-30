#include "coordcontainer.h"


coordcontainer_t*
CreateCoordinateContainer(int xa, int ya) {
	/*summary: allocated memory and returns a pointer
	args:
		int xa -> x coordinate
		int ya -> y coordinate
	*/

	// assigning memory for container
	coordcontainer_t* cntptr = malloc(sizeof(coordcontainer_t));
	// assigning memory for the coordinate
	coord_t* cptr = createCoordinate(xa, ya);
	cntptr->data = cptr;
	// assigning the head;
	if (head == NULL) {
		head = cntptr;
		cntptr->next = NULL;
	}
	else {
		/*
		[head]->[x,y]
		adding new [x1, y1]
		[head]->[x1,y1]->[x,y]
		*/
		cntptr->next = head;
		head = cntptr;
	}
	printf("(container) Memory Created: %p\n", cntptr);
	return cntptr;
}
bool DeleteCoordinateContainer(coordcontainer_t* cntptr) {
	/*summary: frees the memory*/

	coordcontainer_t* temp = head;
	coordcontainer_t* prev = NULL;
	/*
	finding the previous coordinate
	*/
	while (temp != NULL) {
		if (temp->next == cntptr) {
			prev = temp;
			break;
		}
		temp = temp->next;
	}

	if ((prev == NULL) && (cntptr == head)
		&& (cntptr != NULL)) {
		/*cntptr is the head ptr; remove the head*/

		/*if next pointer doesnt exist; 
		set the head to NULL*/
		if (cntptr->next == NULL) {
			head = NULL;
		}
		else {
			head = cntptr->next;
		}

		deleteCoordinate(cntptr->data);
		printf("(container) Memory Freed 1 %p\n", cntptr);
		free(cntptr);
		return true;
	}
	else if ((prev != NULL)) {
		/*obtaining the next coordinate in cntptr 
		and replace the prev coordinate next pointer
		with it and deleting container*/
		coordcontainer_t* ptrnext = cntptr->next;
		prev->next = ptrnext;

		deleteCoordinate(cntptr->data);
		printf("(container) Memory Freed 2 %p\n", cntptr);
		free(cntptr);
		return true;
	}

	return false;
}

void PrintCoordinate(coord_t* cptr) {
	printf("| %d | %d |\n", cptr->x, cptr->y);
	return;
}


void PrintCoordinateContainer() {
	if (head == NULL) {
		printf("no coordinates added\n");
		return;
	} 
	coordcontainer_t* temp = head;
	printf("|  x  |  y  |\n");
	while (temp != NULL) {
		// iterate over the
		PrintCoordinate(temp->data);
		temp = temp->next;
	}
	return;
}
