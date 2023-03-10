#include "matrix.h"


void printmatrix(const matrix* m){
	/*summary: prints the matrix
	 *args: const matrix* m -> matrix
	 *ret: none*/	
	int* tM = m->matrix;
	for (int i = 0; i < m->size; i++){
		printf(" %d ", tM[i]);
	}
	printf("\n");
}


void freeMatrix(matrix* m){
	/*summary: free the matrix 
	 * from the heap
	 *args:matrix* m -> pointer to to a matrix;
	 *ret: none*/
	free(m->matrix);
	free(m);
	return;
}


matrix* createIdentityMatrix(int dim){
	/*summary: creates an identity matrix
	 *args: int dim ->  number of dimensions
			2 -> 2x2
			3 -> 3x3
			4 -> 4x4
	 *ret: matrix -> Identity Matrix*/
	int size = dim*dim;
	matrix* m = malloc(sizeof(matrix));
	int* arr = calloc(size, sizeof(int));
	// row count and col count
	int row = 0;
	int col = 0;
	for (int i = 1; i <= dim; i++) 
		arr[((dim+1)*i-dim) - 1] = 1;
	m->matrix = arr;
	m->size = size;
	m->rowc = dim;
	m->colc = dim;
	return m;
}

matrix* createMatrix(int row, int col, ...){
	/*summary: create a matrix with shape of row x col 
	 * and include the data for the matrix provided
	 *args: int row -> row count
	 	int col -> col count
		... -> data for the matrix
		remember matrix start with 0-index;
	 *ret: matrix * -> row x col matrix*/
	int size = row * col;
	matrix* m = malloc(sizeof(matrix));
	int* arr = malloc(sizeof(int) * size);
	va_list ptr;
	va_start(ptr, col);

	for(int i = 0; i < size; i++){
		arr[i] = va_arg(ptr, int);	
	}
	va_end(ptr);
	m->matrix = arr;
	m->rowc = row;
	m->colc = col;
	m->size = size;
	return m;
}
