#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>

#define DEBUG 1

// matrix structure
typedef struct matrix_ {
	int* matrixptr; // pointer to the matrix
	int size; // size of the matrix
	int row; // row count
	int col; // col count
} matrix;

// forward declaration
//matrix* createMatrix(int row, int col, ...);
//int getSize(matrix* m);

void createMatrix(int row, int col, ...) {
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
	//int* matptr = malloc(sizeof(int) * (row * col));

	// row and col count
	int rc_count = row * col;
	int row_count = 0;
	int col_count = 0;

	va_list ptr;
	va_start(ptr, col);
	for (int i = 0; i < rc_count; i++) {
		float data = va_arg(ptr, float);
#ifdef DEBUG
		printf("data at (%d, %d) = %.2f\n",
			row_count, col_count, data);
#endif
		if ((rc_count%col) == 0) row_count++;
		if (col_count == col) col_count = 0;

		col_count++;
	}


	// loading the data to the matrix
	//for (int i = 0; i < (row * col); i++) {
	//}
	va_end(ptr);

};



int getSize(matrix* m) {
	return m->size;
}



#endif // MATRIX_H
