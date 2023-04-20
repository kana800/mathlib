#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>

typedef struct __matrix__{
	int* arr;
	int size; // size of the matrix
	int rowc; // row count
	int colc; // col count
} matrix;

void printmatrix(const matrix* m){
	/*summary: prints the matrix
	 *args: const matrix* m -> matrix
	 *ret: NIL*/	
	int* tM = m->arr;
	int colcount = m->colc;
	fprintf(stdout,"--");
	for (int i = 0; i < m->size; i++){
		if ((i+1) % m->colc == 1){
			fprintf(stdout,"\n");
		}
		fprintf(stdout," %d ", tM[i]);
	}
	fprintf(stdout,"\nshape (%d,%d)\n--\n",
			m->rowc, m->colc);
}

void freeMatrix(matrix* m){
	/*summary: free the matrix 
	 * from the heap
	 *args: matrix* m -> pointer 
	 	to to a matrix;
	 *ret: NIL*/
	free(m->arr);
	free(m);
	return;
}

matrix* createIdentityMatrix(int d){
	/*summary: creates an identity matrix
	 *args: int dim ->  number of dimensions
			2 -> 2x2
			3 -> 3x3
			4 -> 4x4
	 *ret: matrix -> Identity Matrix*/
	int size = d * d;
	matrix* m = malloc(sizeof(matrix));
	int* arr = calloc(size, sizeof(int));
	// row count and col count
	int row = 0;
	int col = 0;
	for (int i = 1; i <= d; i++) 
		arr[((d+1)*i-d) - 1] = 1;
	m->arr = arr;
	m->size = size;
	m->rowc = d;
	m->colc = d;
	return m;
}

matrix* createMatrix(int row, int col, ...){
	/*summary: create a matrix with shape of row x col
	 * and include the data for the matrix provided
	 *args: int row -> row count
	 	int col -> col count
		... -> data for the matrix
			!!Remember matrix start with 
			0-index; it is expected by the 
			user to provide correct number
			of elements
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
	m->arr = arr;
	m->rowc = row;
	m->colc = col;
	m->size = size;
	return m;
}


void copyMatrix(matrix* a, matrix* b){
	/*summary: copy the content of 
	 * matrix a to matrix b
	 *args: 
	 	matrix* a -> pointer to 
			a matrix
		matrix* b -> pointer to 
			b matrix
	 *if matrix b is not empty the content 
	 will be overwritten
	 *return: NIL*/
	int size_a = a->size;
	b->size = a->size;
	b->rowc = a->rowc;
	b->colc = a->colc;
	int* arr = a->arr;
	int* barr = b->arr;
	for (int i = 0; i < size_a; i++){
		barr[i] = arr[i];
	}
	return;
}

matrix* createEmptyMatrix(int row, int col){
	/*summary: create an empty matrix with shape 
	 * of row x col and data will be zero-initialized
	 *args: int row -> row count
	 	int col -> col count
		remember matrix start with 0-index;
		it is expected by the user to provide
		correct number of elements
	 *ret: matrix * -> row x col matrix*/
	int size = row * col;
	matrix* m = malloc(sizeof(matrix));
	int* arr = calloc(size, sizeof(int));
	m->arr = arr;
	m->rowc = row;
	m->colc = col;
	m->size = size;
	return m;
}


int getIndex(matrix *a, int n, int j){
	/*summary: return an starting index of
	 * appopriate row
	 *args: matrix* a -> matrix
	 	int j -> col id
		int n -> row id
	 *       r  1 2 3    
	 * aug = 1 [3 4 5]
	 * 	 2 [16 20]
	 * 	 3 [14 16]
	 *note: row and col starts with 1 
	 *ret: index in the array*/
	if (j > a->colc){
		fprintf(stderr,
			"Col ID is greater than Col count\n");
		return -1;	
	}
	int i = a->colc*(n - 1) + (j - 1);
	if (i < 0){ 
		fprintf(stderr, 
			"Row Or Column Value Is Invalid\n");
		return -1;
	};
	return i;
}

matrix* addMatrix(matrix* a,matrix* b){
      /*summary: add two matrices together 
       *args: matrix* a -> matrix #1
       	      matrix* b -> matrix #2
       *ret: (new matrix) ptr to a matrix*/	

	//is it compatible
	if ((a->rowc != b->rowc) &&
		(a->colc != b->colc)){
		fprintf(stderr, 
			"Matrices Shape Isn't Compatible\n");
		return NULL;
	}

	matrix* m = createEmptyMatrix(a->rowc, b->colc);
	int* A = a->arr;
	int* B = b->arr;
	int* arr = m->arr;
	int size = m->size;

	for (int i = 0; i < size; i++)
		arr[i] = A[i] + B[i]; 
	
	m->arr = arr;
	m->size = size;
	return m;
}


matrix* subMatrix(matrix* a,matrix* b){
      /*summary: sub two matrices together 
       *args: matrix* a -> matrix #1
	      matrix* b -> matrix #2
       *ret: (new matrix) ptr to a matrix*/	

	//is it compatible
	if ((a->rowc != b->rowc) &&
		(a->colc != b->colc)){
		fprintf(stderr, 
			"Matrices Shape Isn't Compatible\n");
		return NULL;
	}

	matrix* m = createEmptyMatrix(a->rowc, b->colc);
	int* A = a->arr;
	int* B = b->arr;
	int* arr = m->arr;
	int size = m->size;

	for (int i = 0; i < size; i++)
		arr[i] = A[i] - B[i]; 
	
	m->arr = arr;
	m->size = size;
	return m;
}


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
	int* A = a->arr;
	int* B = b->arr;
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
		for (int k = 0; k < b->rowc; k++){
			int a_idx = a_rd*(trow - 1) + k;
			int b_idx = b_cd*(k) + tcol;
			int a_val = A[a_idx];
			int b_val = B[b_idx];
			sum += a_val * b_val;
		}
		arr[p] = sum;
		// moving to next column
		tcol += 1;
	}
	m->arr = arr;
	m->size = size;
	return m;
}


matrix* getPermutation(int dim, int r1, int r2){
	/*summary: return permutation Matrix
	 * identity matrix with swapped rows
	 * with dimension size;
	 *args: dim -> dimension of the matrix
		int r1 -> row number #1
		int r2 -> row number #2
		swap r1 -> r2;
	 * ret: (new matrix)ptr to a identity matrix*/
	matrix* i = createIdentityMatrix(dim); 
	int si_r1 = getIndex(i,0,r1);
	int si_r2 = getIndex(i,0,r2);
	for (int a = 0; a < i->rowc; a++){
		int j = i->arr[si_r1];
		i->arr[si_r1] = i->arr[si_r2];
		i->arr[si_r2] = j;
		si_r1++;
		si_r2++;
	}
	return i;
}


matrix* getInverse(matrix* a){
	/*summary: return inverse of a matrix a
	 *args: matrix *a -> matrix that you want
	 the inverse 
	 *ret: (new matrix)ptr to a matrix*/

	// checking if the matrix is invertible
	// obtaining the determinant is not 
	// supported yet; lesson is in future!	

}

matrix* getLowerTriangularMatrix(matrix* a){
	/*summary: return a lower 
	 * triangular matrix 
	 *args: matrix * a -> pointer to a 
	 	matrix
	 *ret: (new matrix)ptr to a 
	 	lower triangular matrix*/
	
	/*checking if matrix is a square*/
	if (a->colc != a->rowc){
		fprintf(stderr, 
			"Cannot Obtain \
			Lower Triangular Matrix;\
			Matrix Isnt Square\n");
		return NULL;
	}
	matrix* ltm = 
		createEmptyMatrix(a->rowc, a->colc);

	/*row count and column count starts with zero*/
	int rowcount = 1;
	int colcount = 0;
	int index = 0;
	for (int i = 0; i < a->rowc; i++){
		for (int j = 0; j < rowcount; j++){
			index = getIndex(a, i, j);
			printf("index %d \n", index);
		}
	}
}

#endif // MATRIX_H
