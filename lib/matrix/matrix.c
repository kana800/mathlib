#include "matrix.h"


void printmatrix(const matrix* m){
	/*summary: prints the matrix
	 *args: const matrix* m -> matrix
	 *ret: none*/	
	int* tM = m->matrix;
	printf("Row Picture: \n");
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
		it is expected by the user to provide
		correct number of elements
	 *ret: matrix * -> row x col matrix*/
	int size = row * col;
	matrix* m = malloc(sizeof(matrix));
	int* arr = calloc(size, sizeof(int));
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

//matrix* addMatrix(matrix* a,matrix* b,...){
	/*summary: add two matrices together or 
	 * multiple matrices together
	 *args: matrix* a -> matrix #1
	 	matrix* b -> matrix #2
	 *ret: (new matrix) ptr to a matrix*/	
//}

matrix* multiplyMatrix(matrix* a, matrix* b){
	/*summary: multiply two matrices together
	 *args: matrix* a -> matrix #1
		matrix* b -> matrix #2
	 *ret: (new matrix) ptr to a matrix*/
	// is it compatible
	if (a->rowc != b->colc){
		fprintf(stderr, 
			"Matrices Shape Isn't Compatible\n");
		return NULL;
	}

	// size of the new matrix
	matrix* m = malloc(sizeof(matrix));
	int size = a->colc * b->rowc;
	m->rowc = a->colc;
	m->colc = b->rowc;
	int* arr = calloc(size, sizeof(int));
	int* A = a->matrix;
	int* B = b->matrix;
	// row dimension and col dimension
	int a_rd = a->rowc;
	int b_cd = b->colc;
	// tracks the row and col of the element
	int trow = 0;
	int tcol = 0;
	for (int p = 0; p < size; p++){
		if (p % a_rd == 0){
			// moving to the next row
			trow += 1;
			tcol =  0;
		}
		int sum = 0;
		printf("C(%d,%d)=\n", trow, tcol);
		for (int k = 0; k < b->rowc; k++){
			int a_idx = a_rd*(trow - 1) + k;
			int b_idx = b_cd*(k) + tcol;
			int a_val = A[a_idx];
			int b_val = B[b_idx];
			printf("A[%d]*B[%d]=%d*%d\n",a_idx,b_idx,a_val,b_val);
			sum += a_val * b_val;
		}
		printf("%d C(%d,%d) -> %d\n",p,trow,tcol, sum);
		arr[p] = sum;
		// moving to next column
		tcol += 1;
	}
	m->matrix = arr;
	m->size = size;
	return m;
}
