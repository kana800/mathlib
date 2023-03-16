#include "matrix.h"


void printmatrix(const matrix* m){
	/*summary: prints the matrix
	 *args: const matrix* m -> matrix
	 *ret: none*/	
	int* tM = m->matrix;
	for (int i = 0; i < m->size; i++){
		printf(" %d ", tM[i]);
	}
	printf("shape (%d,%d)\n",
			m->rowc, m->colc);
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
	m->matrix = arr;
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
	m->matrix = arr;
	m->rowc = row;
	m->colc = col;
	m->size = size;
	return m;
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
	int* A = a->matrix;
	int* B = b->matrix;
	int* arr = m->matrix;
	int size = m->size;

	for (int i = 0; i < size; i++)
		arr[i] = A[i] + B[i]; 
	
	m->matrix = arr;
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
	int* A = a->matrix;
	int* B = b->matrix;
	int* arr = m->matrix;
	int size = m->size;

	for (int i = 0; i < size; i++)
		arr[i] = A[i] - B[i]; 
	
	m->matrix = arr;
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
	m->matrix = arr;
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
	int si_r1 = getRowIndex(i,r1);
	int si_r2 = getRowIndex(i,r2);
	printf("%d-%d\n", si_r1, si_r2);
	for (int a = 0; a < i->rowc; a++){
		int j = i->matrix[si_r1];
		i->matrix[si_r1] = i->matrix[si_r2];
		i->matrix[si_r2] = j;
		si_r1++;
		si_r2++;
	}
	return i;
}


//matrix* getInverse(matrix* a){
//	/*summary: return inverse of a matrix a
//	 *args: matrix *a -> matrix that you want
//	 the inverse 
//	 *ret: (new matrix)ptr to a matrix*/
//}
//
//matrix* swapRow_base(matrix* a, int r1, int r2, int inplace){
//	/*summary: swap rows in the matrices
//	 *args: matrix *a -> matrix #1
//		int r1 -> row 1
//		int r2 -> row 2
//		int inplace -> inplace replacement
//			or get new array
//			default: inplace
//	 */
//}
//
//matrix* var_swaprow(swaprow_args in){
//	/*summary: helperfunction 
//	 * set default args for 
//	 * swapRow_base*/
//	int inplace = in.inplace ? in.inplace : 0;
//	return swapRow_base(in.a, in.r1, 
//			in.r2, inplace);
//}


int getRowIndex(matrix* a, int r){
	/*summary: return an starting index of
	 * appopriate row
	 *args: matrix* a -> matrix
	 	int r -> row id
	 *ret: row number*/
	if (r > a->rowc){
		fprintf(stderr,
			"Row ID is greater than Row count\n");
		return -1;	
	}
	return (a->rowc*(r - 1));
}

int* getRowPtr(matrix *a, int r){
	/*summary: return an array with
	 * with pointerappopriate row
	 *args: matrix* a -> matrix
	 	int r -> row id
	 *ret: row number*/
	if (r > a->rowc){
		fprintf(stderr,
			"Row ID is greater than Row count\n");
		return NULL;	
	}
	
	int si = a->rowc*(r-1);
	int* ra = calloc(a->rowc,sizeof(int));
	for (int c = 0; c >= a->rowc; c++){
		ra[c] = a->matrix[si];
		si++;
	}
	return ra;
}

int getColIndex(matrix *a, int c){
	/*summary: return an starting index of
	 * appopriate row
	 *args: matrix* a -> matrix
	 	int r -> row id
	 *ret: row number*/
	if (c > a->colc){
		fprintf(stderr,
			"Col ID is greater than Col count\n");
		return -1;	
	}
	return (a->colc*(c - 1));
}
