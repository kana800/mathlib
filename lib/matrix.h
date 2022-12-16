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
	float** colmatrix; // pointer to the columns in the matrix
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
	float* matptr = malloc(sizeof(float) * (row * col));
	// pointer to the col matrices
	float* colmtr = malloc(sizeof(float*) * col);
	// allocation of memory for the matrix datastructure
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

	// populating the col matrices
	for (int i = 0; i < rc_count; i++) {
		float* p = &matptr[i];
	}

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

void addMatrix(matrix* a, matrix* c) {
	/*summary: add two matrices together;
	matrix* a will be replaced with the newer
	values;
	args:
		matrix* a = A
		matrix* c = C
		A = A + C
	*/
	// checking for compatibility
	if ((a->row != c->row) 
		|| (a->col != c->col)) {
		fprintf(stderr, "Matrices are not compatible\n");
		return;
	}

	// normal loop; will optimize later
	int a_rc_count = a->row * a->col;
	int c_rc_count = c->row * c->col;
	for (int i = 0; i < a_rc_count; i++) {
		a->matrixptr[i] += c->matrixptr[i];
	}

	return;
}

void subMatrix(matrix* a, matrix* c) {
	/*summary: substract two matrices together; 
	matrix* a will be replaced with the newer values
	args:
		matrix* a = A
		matrix* c = C
		A = A - C
	*/
	// checking for compatibility
	if ((a->row != c->row) 
		|| (a->col != c->col)) {
		fprintf(stderr, "Matrices are not compatible\n");
		return;
	}

	// normal loop; will optimize later
	int a_rc_count = a->row * a->col;
	int c_rc_count = c->row * c->col;
	for (int i = 0; i < a_rc_count; i++) {
		a->matrixptr[i] -= c->matrixptr[i];
	}

	return;
}

matrix* multMatrix(matrix* a, matrix* c) {
	/*summary: multiply two matrices together;
	creates a new matrix and return its ptr
	args:
		matrix* a = A
		matrix* b = B
	ret:	
		ans = A * B

	This is not the best algorithm to multiply
	a matrix with n-dimensions; I am running out
	time hence the shitty O(n^3) implementation

	*/

	// checking for compatibility
	// A (r x c) B (r x c)
	// aC == bR
	// ans matrix dimensions -> aR x bC
	if (a->col != c->row) {
		fprintf(stderr, "Matrices are not compatible\n");
		return a;
	}
	// generate a matrix with ans dimension
	float* matptr = malloc(
		sizeof(float) * (a->row * c->col));

	// iterating through the data
	int a_start = 0;
	int a_end = a->col;

	// keeps in track columns
	int b_start = 0;
	int b_end = c->col;

	float sum = 0;

	for (int i = 0; i < a->row; i++) {
		// obtaining the row values of the Matrix A
		for (int j = a_start, l = b_start; j < a_end; j++) {
#if DEBUG
			printf(
				"row %d: matrixptr a [%d] -> %.2f\t",
				i, j, a->matrixptr[j]);
#endif
			// obtaining the column values of the Matrix B
			// have to repeat this a->row times
		}

		// setting pos in the array
		a_start = a_end;
		a_end += a->col;
	}
	
	return a;
}

void scalarMultMatrix(float a, matrix* b) {
	/*summary: INPLACE Multiplication
	multiply matrix by a scalar value
	args:
		float a = a
		matrix* b = B
		B = a * B
	*/

	// normal loop; will optimize later
	for (int i = 0; i < b->size; i++) {
		b->matrixptr[i] *= a;
	}
}

#endif // MATRIX_H
