#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>

typedef struct __matrix__{
	int* matrix;
	int size; // size of the matrix
	int rowc; // row count
	int colc; // col count
} matrix;

void printmatrix(const matrix* m);
void freeMatrix(matrix* m);

matrix* createIdentityMatrix(int dim);
matrix* createMatrix(int row,int col, ...);
//matrix* addMatrix(matrix* a,matrix* b,...);
matrix* multiplyMatrix(matrix* a, matrix* b);

#endif // MATRIX_H
