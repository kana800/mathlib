#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#define DEBUG 1

// data structure
typedef struct data_ {
	int row; // row number
	int col; // col number
	float d; // data point
	int index; // normal index number
} element;

// element container
typedef struct elementcontainer_ {
	element* e; // matrix information 
	element* next; // pointer to the next element
} elementcontainer;

// matrix structure
typedef struct matrix_ {
	elementcontainer* matrixptr; // pointer to the matrix
	int size; // size of the matrix
	int row; // row count
	int col; // col count
} matrix;

static void printMatrix(matrix* m) {
	/*summary: prints the matrix passed 
	as an argument
	args:
		matrix* m -> pointer to the matrix
	*/

}

matrix* createMatrix(int row, int col, ...) {
	/*summary: creates a matrix structure in 
	the heap and return its pointer
	args:
		int row -> row count
		int col -> col count
		... -> values to be included
	example:
		if you want a 2x2 matrix
			[
			c1 c2
		r1	1  2
		r2	3  -4
			]
		createMatrix(2,2, 1,2,3,-4 )
		- for the insertion of data to the matrix; the values will go
		from r1,c1 -> r1,c2 -> r2,c1 -> r2,c2
	ret:
		matrix* m -> ptr to a matrix object
	*/
	// allocation of memory for the matrix datastructure
	matrix* m = malloc(sizeof(matrix));
	// initializing data;
	m->row = row;
	m->col = col;
	m->matrixptr = NULL;
	m->size = row * col;

	// row and col count
	int rc_count = row * col;
	int row_count = 0;
	int col_count = 0;

	int section = col_count;
	int inc_section = col;


	// elementcontainer
	elementcontainer* nxtptr = NULL;

	va_list ptr;
	va_start(ptr, col);
	for (int i = 0; i < rc_count; i++) {
		float data = (float)va_arg(ptr, int);
		// creating a new element object
		element* tempE = malloc(sizeof(element));
		elementcontainer* tempContainer = malloc(
			sizeof(elementcontainer));

		// end of the row reached
		if (col_count == col) {
			col_count = 0;
			section = row_count;
			inc_section--;
			row_count++;
		}

#ifdef DEBUG
		printf("data at (%d, %d) = %.2f\n",
			row_count + 1, col_count + 1, data);
#endif
		tempE->col = col_count + 1;
		tempE->row = row_count + 1;
		tempE->d = data;
		tempE->index = i;

		// adding data to the element container
		tempContainer->e = tempE;
		tempContainer->next = nxtptr;
		nxtptr = tempContainer;

		//
		col_count++;
		section += inc_section;
	}
	m->matrixptr = nxtptr;
	va_end(ptr);

#ifdef DEBUG
	printf("----------------------------------\n");
#endif

	return m;
};

void freeMatrix(matrix* m) {
	/*summary: release the matrix
	from the heap
	args:
		matrix* m -> matrix 
	*/
	int tSize = m->size;
	// releasing the block memory
	free(m->matrixptr);
	// releasing the matrix
	free(m);
}


void freeContainer(elementcontainer* e) {
	/*summary: release the
	element container from heap
	args:
		elementcontainer* e -> element
	*/
	elementcontainer* tempS = e;
	while (e != NULL) {
		element* tempElement = e->e;
		elementcontainer* tempE = e;

		e = e->next;

		free(tempElement);
		free(tempE);
	}

}

int getSize(matrix* m) {
	/*summary: return the size of
	the given matrix
	args:
		matrix* m -> matrix
	ret:
		int -> size of the matrix
	*/
	return m->size;
}

elementcontainer* getRow(matrix* m, int row) {
	/*summary: returns row from the given matrix
	args:
		matrix* m -> matrix
		int row -> row number
	if given row is greater than number of rows in the
	matrix elementcontainer will be null
	return:
		heap allocated elementcontainer with 
		only the given row;
	note:
		use freeElementContainer();
	*/
	if (row > m->row) return NULL;

	elementcontainer* tempM = m->matrixptr;
	elementcontainer* rowptr = NULL;
	while (tempM != NULL) {
		if (tempM->e->row == row) {
			element* tempE = malloc(sizeof(element));
			elementcontainer* tempRow = 
				malloc(sizeof(elementcontainer));
			// copying the values
			tempE->d = tempM->e->d;
			tempE->row = tempM->e->row;
			tempE->col = tempM->e->col;
			tempE->index = tempM->e->index;
			// container
			tempRow->e = tempE;
			tempRow->next = rowptr;
			rowptr = tempRow;
		}
		tempM = tempM->next;
	}
	return rowptr;
}

elementcontainer* getCol(matrix* m, int col) {
	/*summary: returns col from the given matrix
	args:
		matrix* m -> matrix
		int col -> col number
	if given col is greater than number of cols in the
	matrix elementcontainer will be null
	return:
		heap allocated elementcontainer with 
		only the given col;
	note:
		use freeElementContainer();
	*/
	if (col > m->col) return NULL;

	elementcontainer* tempM = m->matrixptr;
	elementcontainer* colptr = NULL;
	while (tempM != NULL) {
		if (tempM->e->col == col) {
			element* tempE = malloc(sizeof(element));
			elementcontainer* tempRow = 
				malloc(sizeof(elementcontainer));
			// copying the values
			tempE->d = tempM->e->d;
			tempE->row = tempM->e->row;
			tempE->col = tempM->e->col;
			tempE->index = tempM->e->index;
			// container
			tempRow->e = tempE;
			tempRow->next = colptr;
			colptr = tempRow;
		}
		tempM = tempM->next;
	}
	return colptr;
}

float getData(matrix* m, int row, int col) {
	/*summary: returns data from the given
	row and col
	if the row and col is over the size of the matrix
	function will return the last value of the matrix
	args:
		matrix* m -> pointer to the matrix
		int row -> row
		int col -> col
	ret:
		float -> m->e->d [matrixptr->elementcontainer->data]
	*/

	// checking if the given row size and col size is 
	// overbounds
	if ((row > m->row) || (col > m->col))
		return m->matrixptr->e->d;

	elementcontainer* tempE = m->matrixptr;
	while (tempE != NULL) {
		if ((row == tempE->e->row)
			&& (col == tempE->e->col)) {
			return tempE->e->d;
		}
		tempE = tempE->next;
	}
	return m->matrixptr->e->d;
}

void addMatrix(matrix* a, matrix* b) {
	/*summary: add two matrices together
	args:
		matrix* a -> matrix one
		matrix* b -> matrix two
	addition values of mat a + mat b will be replaced 
	inplace of mat a
	ie:
		MAT A + MAT B = MAT A
	*/

	// check if the rows and col are 
	// same size
	if ((a->row == b->row) 
		&& (a->col == b->col)) {
		// looping through the matrices 
		elementcontainer* tempA = a->matrixptr;
		elementcontainer* tempB = b->matrixptr;
		while ((tempA != NULL) || (tempB != NULL)) {

#ifdef  DEBUG == 0
			printf("MAT A + MAT B: \n\t"
				"(%d, %d) %.2f + (%d,%d) %.2f = %.2f\n",
				tempA->e->row, tempA->e->col,
				tempA->e->d,
				tempB->e->row, tempB->e->col,
				tempB->e->d,
				tempA->e->d + tempB->e->d);
#endif
			tempA->e->d += tempB->e->d;
			tempA = tempA->next;
			tempB = tempB->next;
		}
	}
	else {
		fprintf(stderr, "Incompatible Matrices\n");
		return;
	}

}

void subMatrix(matrix* a, matrix* b) {
	/*summary: substract two matrices together
	args:
		matrix* a -> matrix one
		matrix* b -> matrix two
	substracted values of mat a - mat b will be replaced 
	inplace of mat a
	ie:
		MAT A - MAT B = MAT A
	*/

	// check if the rows and col are 
	// same size
	if ((a->row == b->row) 
		&& (a->col == b->col)) {
		// looping through the matrices 
		elementcontainer* tempA = a->matrixptr;
		elementcontainer* tempB = b->matrixptr;
		while ((tempA != NULL) || (tempB != NULL)) {

#ifdef  DEBUG
			printf("MAT A - MAT B: \n\t"
				"(%d, %d) %.2f - (%d,%d) %.2f = %.2f\n",
				tempA->e->row, tempA->e->col,
				tempA->e->d,
				tempB->e->row, tempB->e->col,
				tempB->e->d,
				tempA->e->d - tempB->e->d);
#endif
			tempA->e->d -= tempB->e->d;
			tempA = tempA->next;
			tempB = tempB->next;
		}
	}
	else {
		fprintf(stderr, "Incompatible Matrices\n");
		return;
	}

}

#endif // MATRIX_H
