#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#define DEBUG 1

// matrix structure
typedef struct matrix_ {
	float* matrixptr; // pointer to the matrix
	int size; // size of the matrix
	int row; // row count
	int col; // col count
} matrix;

// forward declaration
//matrix* createMatrix(int row, int col, ...);
//int getSize(matrix* m);

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
	float* matptr = malloc(sizeof(float) * (row * col) + 2);
	matrix* m = malloc(sizeof(matrix));
	
	// initializing data;
	m->row = row;
	m->col = col;
	m->matrixptr = matptr;
	m->size = row * col;

	// row and col count
	int rc_count = row * col;
	int row_count = 0;
	int col_count = 0;

	va_list ptr;
	va_start(ptr, col);
	for (int i = 0; i < rc_count; i++) {
		float data = (float)va_arg(ptr, int);
		matptr[i] = data;
		if (col_count == col) {
			col_count = 0;
			row_count++;
		}
#ifdef DEBUG
		printf("data at (%d, %d) = %.2f\n",
			row_count + 1, col_count + 1, data);
#endif
		col_count++;
	}
	va_end(ptr);
	return m;
};

void freeMatrix(matrix* m) {
	/*summary: release the 
	memory of the matrix
	args:
		matrix* m -> matrix 
	*/
	int tSize = m->size;
	// releasing the block memory
	free(m->matrixptr);
	// releasing the matrix
	free(m);
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


float getData(matrix* m,int row, int col) {
	/*summary: return the data in the
	row and col location
	args:
		matrix* m -> matrix
		int row -> row number
		int col -> col number
	errorhandling:
		if the row count is exceeds
		data point you will get the
		last data point of the matrix
	ret:
		float -> data at the given loc
	*/
	int rowcount = (row - 1) * (col - 1);
	// checking if valid row count is given
	if (rowcount > m->size) {
		perror(
			"Given Row and Col Combination"
			"Exceed Matrix Size\n");
		return m->matrixptr[m->size];
	}
	return m->matrixptr[rowcount];
}

void addMatrix(matrix* a, matrix* c);

#endif // MATRIX_H
