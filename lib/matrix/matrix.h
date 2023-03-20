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

typedef struct {
	matrix* a;
	int r1;
	int r2;
	int inplace;
} swaprow_args;

void printmatrix(const matrix* m);
void freeMatrix(matrix* m);

matrix* createIdentityMatrix(int dim);
matrix* createMatrix(int row,int col, ...);
matrix* createEmptyMatrix(int row,int col);

// matrix operations
matrix* addMatrix(matrix* a,matrix* b);
matrix* subMatrix(matrix* a,matrix* b);
matrix* multiplyMatrix(matrix* a, matrix* b);
//matrix* getInverse(matrix* a);

matrix* getPermutation(int dim, int r1, int r2);

// helper function
int getRowIndex(matrix* a, int r);
int getColIndex(matrix* a, int j, int n);


#endif // MATRIX_H
