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

static void printElementContainer(elementcontainer* e);
matrix* createMatrix(int row, int col, ...);
matrix* createEmptyMatrix(int row, int col); 
void freeMatrix(matrix* m);
void freeContainer(elementcontainer* e);
elementcontainer* getRow(matrix* m, int row);
elementcontainer* getCol(matrix* m, int col); 
float getData(matrix* m, int row, int col); 
void addMatrix(matrix* a, matrix* b);
void subMatrix(matrix* a, matrix* b);
float multiplyMatrixHelper(elementcontainer* r, elementcontainer* c); 
matrix* multiplyMatrix(matrix* a, matrix* b); 

#endif // MATRIX_H
