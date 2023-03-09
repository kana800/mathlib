#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

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

#endif // MATRIX_H
