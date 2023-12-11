#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>

#ifdef __AVX__
  #include <immintrin.h>
#else
  #warning AVX IS NOT AVAILABLE. CANNOT COMPILE!
#endif

// matrix structure
typedef struct __matrix__ {
	int* arr; // contains data of the matrix
	int size; // size of the matrix
	int rowc; // row count
	int colc; // col count
} matrix;

// augmented matrix
typedef struct __augmatrix__ {
	matrix* arr_a; // pointer to matrix a
	matrix* arr_b; // pointer to matrix b
} augmatrix;


void printmatrix(const matrix* m) {
	if (m == NULL) return;
	int* tM = m->arr;
	int colcount = m->colc;
	fprintf(stdout,"---");
	for (int i = 0; i < m->size; i++)
	{
		if ((i+1) % m->colc == 1)
		{
			fprintf(stdout,"\n");
		}
		fprintf(stdout," %d ", tM[i]);
	}
	fprintf(stdout,
		"\nshape (%d,%d)\n--\n",
		m->rowc, m->colc);
	return;
}

void freeMatrix(matrix* m) {
	free(m->arr);
	free(m);
	return;
}

void freeAugmentedMatrix(augmatrix* m) {
	matrix* a = m->arr_a;
	matrix* b = m->arr_b;

	free(m);
	freeMatrix(a);
	freeMatrix(b);
	return;
}

// summary: creates an identity matrix
// args: int dim ->  number of dimensions
// 		2 -> 2x2
// 		3 -> 3x3
// 		4 -> 4x4
// 		[ 1 0 0 ]
// 		[ 0 1 0 ]
// 		[ 0 0 1 ]
// ret: matrix -> Identity Matrix
matrix* createIdentityMatrix(int d) {
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

// summary: create a matrix with shape of row x col
//  and include the data for the matrix provided
// args: int row -> row count
//  	int col -> col count
// 	    ... -> data for the matrix
// note: Remember matrix start with 
// 		0-index; it is expected by the 
// 		user to provide correct number
// 		of elements
// ret: matrix * -> row x col matrix
matrix* createMatrix(int row, int col, ...)
{
	int size = row * col;
	matrix* m = malloc(sizeof(matrix));
	int* arr = calloc(size, sizeof(int));
	
	va_list ptr;
	va_start(ptr, col);

	for(int i = 0; i < size; i++)
	{
		arr[i] = va_arg(ptr, int);	
	}

	va_end(ptr);
	
	m->arr = arr;
	m->rowc = row;
	m->colc = col;
	m->size = size;
	return m;
}

// TODO THIS IS NOT A DEEP COPY 
// THIS IS SHALLOW COPY FIX THIS
// summary: copy the content of 
//   matrix a to matrix b
// args: 
//  	matrix* a -> pointer to 
// 		a matrix
// 	matrix* b -> pointer to 
// 		b matrix
// note: if matrix b is not empty the content 
// 	will be overwritten
void copyMatrix(matrix* a, matrix* b)
{
	int size_a = a->size;
	b->size = a->size;
	b->rowc = a->rowc;
	b->colc = a->colc;
	int* arr = a->arr;
	int* barr = b->arr;
	for (int i = 0; i < size_a; i++)
	{
		barr[i] = arr[i];
	}
	return;
}

// summary: create an empty matrix with shape 
//  of row x col and data will be zero-initialized
// args: int row -> row count
//  	int col -> col count
// note: remember matrix start with 0-index;
// 	it is expected by the user to provide
// 	correct number of elements
// ret: matrix * -> row x col matrix
matrix* createEmptyMatrix(int row, int col) {
	int size = row * col;
	matrix* m = malloc(sizeof(matrix));
	int* arr = calloc(size, sizeof(int));
	m->arr = arr;
	m->rowc = row;
	m->colc = col;
	m->size = size;
	return m;
}

// summary: return an starting index of
//  appopriate row
// args: matrix* a -> matrix
//  	int j -> col id
// 	int n -> row id
//        r  1 2 3    
//  aug = 1 [3 4 5]
//  	  2 [16 20]
//  	  3 [14 16]
// note: row and col starts with 1 
// ret: index in the array
int getIndex(matrix *a, int n, int j) {
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

// summary: create an augmented matrix
//  by appending the columns of two given matrices
// args:
// 	matrix* a -> matrix 1
// 	matrix* b -> matrix 2
// 	a = [1 3 2] b=[4]
// 	    [2 0 1]   [3]
// 	    [5 2 2]   [1]
// 	augmented = [1 3 2 |4]
// 		    	[2 0 1 |3]
// 		    	[5 2 2 |1]
// ret: matrix * -> pointer to a matrix
augmatrix* createAugmentedMatrix(matrix* a, matrix* b)
{
	if (a->rowc != b->rowc)
	{
		fprintf(stderr, 
			"Cannot Create An Augmented Matrix");
		return NULL;
	}

	matrix* temp_a = 
		createEmptyMatrix(a->rowc, a->colc);
	matrix* temp_b = 
		createEmptyMatrix(b->rowc, b->colc);
	copyMatrix(a, temp_a);
	copyMatrix(b, temp_b);
	
	augmatrix* m = (augmatrix*)malloc(sizeof(augmatrix));
	m->arr_a = temp_a;
	m->arr_b = temp_b;
	return m;	
}

// summary: inplace multiply augmented
//  matrix with a scalar value;
// args: augmatrix *a -> augmented matrix 
//  	int s -> scalar value
void aug_multiplyByScalar(augmatrix* a, int s)
{
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;
	for (int i = 0; i < mat_a->size ; i++)
	{
		mat_a->arr[i] *= s; 
	}
	for (int i = 0; i < mat_b->size ; i++)
	{
		mat_b->arr[i] *= s; 
	}
}


// summary: add a scalar to a given row;
// args: augmatrix *a -> augmented matrix 
// 	int row -> row count
// 	int s -> scalar value
void aug_addScalarToRow(augmatrix* a, int row, int s)
{
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if (row > mat_a->rowc)
	{
		fprintf(stderr,"Row Count is High\n");
		return;
	}
	
	int row_a = getIndex(mat_a,row, 1);
	int row_b = getIndex(mat_b,row, 1);

	for (int i = 0; i < mat_a->colc; i++)
	{
		mat_a->arr[row_a] += s; 
		row_a += 1;
	}

	for (int i = 0; i < mat_b->colc; i++)
	{
		mat_b->arr[row_b] += s; 
		row_b += 1;
	}

	return;
}

// summary: substract a scalar from a given row;
// args: augmatrix *a -> augmented matrix 
// 	int row -> row count
// 	int s -> scalar value
void aug_subScalarFromRow(augmatrix* a, int row, int s)
{
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if (row > mat_a->rowc)
	{
		fprintf(stderr,"Row Count is High\n");
		return;
	}
	
	int row_a = getIndex(mat_a,row, 1);
	int row_b = getIndex(mat_b,row, 1);

	for (int i = 0; i < mat_a->colc; i++)
	{
		mat_a->arr[row_a] -= s; 
		row_a += 1;
	}

	for (int i = 0; i < mat_b->colc; i++)
	{
		mat_b->arr[row_b] -= s; 
		row_b += 1;
	}
	return;
}

// summary: add two rows together
// args: augmatrix* a -> augmented matrix 
//  	int r1 -> row #1 
// 	int r2 -> row #2
// 	int r3 -> row #3
// 	r3 = r1 + r2;
void aug_addRow(augmatrix* a, int r1, int r2, int r3)
{
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if ((r1 > mat_a->rowc) ||
		(r2 > mat_a->rowc) ||
		(r3 > mat_a->rowc))
	{
		fprintf(stderr, "Row Count is High\n");
		return;
	}

	// get the starting indexes of all the rows
	int row_a_r1 = getIndex(mat_a, r1, 1); 
	int row_a_r2 = getIndex(mat_a, r2, 1); 
	int row_a_r3 = getIndex(mat_a, r3, 1); 
	
	int row_b_r1 = getIndex(mat_b, r1, 1); 
	int row_b_r2 = getIndex(mat_b, r2, 1); 
	int row_b_r3 = getIndex(mat_b, r3, 1); 


	for (int i = 0; i < mat_a->colc; i++)
	{
		mat_a->arr[row_a_r3] = 
			mat_a->arr[row_a_r1] + 
			mat_a->arr[row_a_r2]; 
		row_a_r1 += 1; 
		row_a_r2 += 1; 
		row_a_r3 += 1; 
	}

	for (int i = 0; i < mat_b->colc; i++)
	{
		mat_b->arr[row_b_r3] = 
			mat_b->arr[row_b_r1] + 
			mat_b->arr[row_b_r2]; 
		row_b_r1 += 1; 
		row_b_r2 += 1; 
		row_b_r3 += 1; 
	}

	return;
}

// summary: add two rows together
// args: augmatrix* a -> augmented matrix 
//  	int r1 -> row #1 
// 	int r2 -> row #2
// 	int r3 -> row #3
// 	r3 = r1 - r2;
void aug_subRow(augmatrix* a, int r1, int r2, int r3) 
{
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if ((r1 > mat_a->rowc) ||
		(r2 > mat_a->rowc) ||
		(r3 > mat_a->rowc))
	{
		fprintf(stderr, "Row Count is High\n");
		return;
	}

	// get the starting indexes of all the rows
	int row_a_r1 = getIndex(mat_a, r1, 1); 
	int row_a_r2 = getIndex(mat_a, r2, 1); 
	int row_a_r3 = getIndex(mat_a, r3, 1); 
	
	int row_b_r1 = getIndex(mat_b, r1, 1); 
	int row_b_r2 = getIndex(mat_b, r2, 1); 
	int row_b_r3 = getIndex(mat_b, r3, 1); 

	for (int i = 0; i < mat_a->colc; i++)
	{
		mat_a->arr[row_a_r3] = 
			mat_a->arr[row_a_r1] - 
			mat_a->arr[row_a_r2]; 
		row_a_r1 += 1; 
		row_a_r2 += 1; 
		row_a_r3 += 1; 
	}

	for (int i = 0; i < mat_b->colc; i++)
	{
		mat_b->arr[row_b_r3] = 
			mat_b->arr[row_b_r1] - 
			mat_b->arr[row_b_r2]; 
		row_b_r1 += 1; 
		row_b_r2 += 1; 
		row_b_r3 += 1; 
	}

	return;
}

// summary: return the col; given 
//  the index value 
// args: matrix* a -> pointer to
//   matrix 
//   int idx -> index of the 
//   matrix 
// ret: col number
int getCol(matrix* a, int idx)
{
	int col = (idx + 1) % a->colc;
	return (col == 0) ? a->colc : col;
}


// summary: return the row; given 
//  the index value 
// args: matrix* a -> pointer to
//   matrix 
//   int idx -> index of the 
//   matrix 
// ret: row number
int getRow(matrix* a, int idx)
{
	int col = getCol(a, idx);
	int cnst = a->colc - (col - 1);
	int ans = (idx + cnst) / a->colc;
	return (idx + cnst) / a->colc;
}


// summary: add two matrices together 
// args: matrix* a -> matrix #1
//      matrix* b -> matrix #2
// ret: (new matrix) ptr to a matrix	
matrix* addMatrix(matrix* a,matrix* b)
{
	//is it compatible
	if ((a->rowc != b->rowc) &&
		(a->colc != b->colc))
	{
		fprintf(stderr, 
				"Matrices Shape Isn't Compatible\n");
		return NULL;
	}

	matrix* m = createEmptyMatrix(a->rowc, b->colc);
	int* A = a->arr;
	int* B = b->arr;
	int* arr = m->arr;
	int size = m->size;

	int remaining = size % 8;
	int loopend = size - remaining;

	for(int i = 0; i < loopend; i += 8)
	{
		__m256i arr_a = _mm256_loadu_si256((__m256i*)&A[i]);
		__m256i arr_b = _mm256_loadu_si256((__m256i*)&B[i]);
		__m256i result = _mm256_add_epi32(arr_a, arr_b);
		_mm256_storeu_si256((__m256i*)&arr[i], result);
	}

	for (int i = loopend; i < size; i++)
	{
		arr[i] = A[i] + B[i];
	}

	m->arr = arr;
	m->size = size;
	return m;
}


// summary: sub two matrices together 
// args: matrix* a -> matrix #1
// 		matrix* b -> matrix #2
// ret: (new matrix) ptr to a matrix*/	
matrix* subMatrix(matrix* a,matrix* b)
{
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

	int remaining = size % 8;
	int loopend = size - remaining;

	for(int i = 0; i < loopend; i += 8)
	{
		__m256i arr_a = _mm256_loadu_si256((__m256i*)&A[i]);
		__m256i arr_b = _mm256_loadu_si256((__m256i*)&B[i]);
		__m256i result = _mm256_sub_epi32(arr_a, arr_b);
		_mm256_storeu_si256((__m256i*)&arr[i], result);
	}

	for (int i = loopend; i < size; i++)
	{
		arr[i] = A[i] - B[i];
	}
	
	m->arr = arr;
	m->size = size;
	return m;
}


// summary: multiply two matrices together
// args: matrix* a -> matrix #1
//   	matrix* b -> matrix #2
// ret: (new matrix) ptr to a matrix*/
matrix* multiplyMatrix(matrix* a, matrix* b)
{
	// is it compatible
	if (a->colc != b->rowc){
		fprintf(stderr, 
			"Matrices Shape Isn't Compatible\n");
		return NULL;
	}

	// size of the new matrix
	matrix* m = malloc(sizeof(matrix));
	int size = a->rowc * b->colc;
	m->rowc = a->rowc;
	m->colc = b->colc;
	int* arr = calloc(size, sizeof(int));
	int* A = a->arr;
	int* B = b->arr;
	// row dimension and col dimension
	int a_rd = a->rowc;
	int b_cd = b->colc;
	// tracks the row and col of the element
	int trow = 0;
	int tcol = 0;

	for (int p = 0; p < size; p++)
	{
		if (p % a_rd == 0){
			// moving to the next row
			trow += 1;
			tcol =  0;
		}
		int sum = 0;
		for (int k = 0; k < b->colc; k++){
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


matrix* getPermutationMatrix(int dim, int r1, int r2){
	/*summary: return permutation Matrix
	 * identity matrix with swapped rows
	 * with dimension size;
	 *args: dim -> dimension of the matrix
		int r1 -> row number #1
		int r2 -> row number #2
		swap r1 -> r2;
	 * ret: (new matrix)ptr to a identity matrix*/
	matrix* i = createIdentityMatrix(dim); 
	int si_r1 = getIndex(i,r1,1);
	int si_r2 = getIndex(i,r2,1);
	for (int a = 0; a < i->rowc; a++){
		int j = i->arr[si_r1];
		i->arr[si_r1] = i->arr[si_r2];
		i->arr[si_r2] = j;
		si_r1++;
		si_r2++;
	}
	return i;
}


void multiplyRow(matrix* a, int row, int s){
	/*summary: simple row multiplication
	 *args: matrix* a -> pointer to matrix 
	 	int row -> row of matrix 
		int s -> scalar value 
	 *ret: NIL*/
	if (row >= a->rowc){
		fprintf(stderr, 
			"Given Row Is Greater\
			Than Actual Row");
		return;
	}
	// grabbing the start index
	int sidx;
	for (int i = 1; i <= a->colc; i++){
		sidx = getIndex(a, row, i);
		a->arr[sidx] *= s; 
	}
};


void divideRow(matrix* a, int row, int s){
	/*summary: divide row in a matrix
	 *args: matrix* a -> pointer to matrix 
	 	int row -> row of matrix 
		int s -> scalar value 
	 *ret: NIL*/
	if (row >= a->rowc){
		fprintf(stderr, 
			"Given Row Is Greater\
			Than Actual Row");
		return;
	}
	// grabbing the start index
	int sidx = getIndex(a, row, 1);
	for (int i = 1; i <= a->rowc; i++, sidx++){
		a->arr[sidx] /= s; 
	}
}


void multiplyColumn(matrix* a, int col, int s){
	/*summary: simple col multiplication
	 *args: matrix* a -> pointer to matrix 
	 	int col -> col of matrix 
		int s -> scalar value 
	 *ret: NIL*/
};


void addScalarToMatrix(matrix* a, int s){
	/*summary: [inplace-addition] add 
	 * a scalar value to the whole matrix
	 *args: matrix* a -> pointer to matrix 
		int s -> scalar value 
	 *ret: NIL*/
	for (int i = 0; i < a->size; i++){
		a->arr[i] += s;
	}
	return;
}

void subScalarFromMatrix(matrix* a, int s){
	/*summary: [inplace-addition] substract 
	 * a scalar value to the whole matrix
	 *args: matrix* a -> pointer to matrix 
		int s -> scalar value 
	 *ret: NIL*/
	for (int i = 0; i < a->size; i++){
		a->arr[i] -= s;
	}
	return;
}

void swapRows(matrix* a, int r1, int r2){
	/*summary: swap rows in the matrix 
	 *args: matrix* a-> ptr to a matrix
		int r1 -> row number #1
		int r2 -> row number #2
		swap r1 -> r2;
	 * ret: matrix * a*/ 
	int si_r1 = getIndex(a, r1, 1);
	int si_r2 = getIndex(a, r2, 1);
	for (int i = 0; i < a->colc; i++){
		 int temp = a->arr[si_r1]; 
		 a->arr[si_r1] = a->arr[si_r2];
		 a->arr[si_r2] = temp;
		 si_r1++;
		 si_r2++;
	}
	return;
}


matrix* getInverse(matrix* a){
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
	int colcount = 1;
	int index = 0;
	for (int i = 0; i < a->rowc; i++){
		for (int j = 0; j < colcount; j++){
			index = getIndex(a, i + 1, j + 1);
			ltm->arr[index] = a->arr[index];
		}
		colcount++;
	}
	return ltm;
}

// summary: return a upper triangular 
// args: matrix * a -> pointer to a 
//   matrix
// ret: (new matrix)ptr to a 
//	lower triangular matrix
matrix* getUpperTriangularMatrix(matrix* a)
{
	/*checking if matrix is a square*/
	if (a->colc != a->rowc){
		fprintf(stderr, 
			"Cannot Obtain \
			Upper Triangular Matrix;\
			Matrix Isnt Square\n");
		return NULL;
	}
	matrix* utm = 
		createEmptyMatrix(a->rowc, a->colc);
	/*row count and column count starts with zero*/
	int index = 0;
	for (int i = 1; i <= a->rowc; i++){
		for (int j = i; j <= a->colc; j++){
			index = getIndex(a, i, j);
			utm->arr[index] = a->arr[index];
		}
	}
	return utm;
}

void transposematrix(matrix* m)
{

}

#endif // MATRIX_H
