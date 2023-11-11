/*test cases for the matrix library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "matrix.h"

#define MATRIXCOMPARISONWITHARR(matrix, array, size) \
	compareMatricesWithArr(matrix, array, size, __LINE__)

// summary: compare matrix a with b
// args: matrix * a -> pointer to matrix a
//   matrix * b -> pointer to matrix b
void compareMatrices(matrix* a, matrix* b)
{
	//comparing the sizes
	assert(a->size == b->size);
	//comparing the rows and columns
	assert(a->rowc == b->rowc);
	assert(a->colc == b->colc);
	//comparing data inside the matrices
	for (int i = 0; i < a->size; i++)
		assert(a->arr[i] == b->arr[i]);	
	return;
}

// summary: compare matrix a's arr with arr 
// args: matrix * a -> pointer to matrix a
// 	int* arr -> int pointer
// 	int size -> size of the array
// ret: NIL
void compareMatricesWithArr(matrix* a, int* arr, int size, int line)
{
	for (int i = 0; i < size; i++)
	{
		if (a->arr[i] != arr[i])
			fprintf(stderr, "error@line%d %d!=%d\n", line , a->arr[i], arr[i]);
	}
	return;
}


int main(int argc, char *argv[]){
	// matrix.h
	
	// testing creation of matrices 
	// creating an identity matrix
	// id_3 = [1 0 0]
	//        [0 1 0]
	//        [0 0 1]
	matrix* id_3 = createIdentityMatrix(3);
	// id_2 = [1 0]
	//        [0 1]
	matrix* id_2 = createIdentityMatrix(2);

	int id_local_3[9] = {1,0,0,0,1,0,0,0,1};  
	MATRIXCOMPARISONWITHARR(id_3, id_local_3, 9);

	int id_local_2[4] = {1,0,0,1}; 
	MATRIXCOMPARISONWITHARR(id_2, id_local_2, 4);

	freeMatrix(id_3);
	freeMatrix(id_2);

	// creating an empty matrix
	matrix* e_3 = createEmptyMatrix(3, 3);
	int id_empty_3[9] = {0,0,0,0,0,0,0,0,0};
	MATRIXCOMPARISONWITHARR(e_3, id_empty_3, 9);

	// testing matrix operations
	// addition and substraction from 
	// whole matrix
	//
	// before addScalarToRow(e_3, 2);  
	// e_3 = [0 0 0]
	//       [0 0 0]
	//       [0 0 0]
	// after 
	// e_3 = [2 2 2]
	//       [2 2 2]
	//       [2 2 2]
	int id_empty_4[9] = {2,2,2,2,2,2,2,2,2};
	addScalarToMatrix(e_3, 2);
	MATRIXCOMPARISONWITHARR(e_3, id_empty_4, 9);

	// before subScalarToRow(e_3, 1);  
	//  e_3 = [2 2 2]
	//        [2 2 2]
	//        [2 2 2]
	//  after
	//  e_3 = [1 1 1]
	//        [1 1 1]
	//        [1 1 1]
	subScalarFromMatrix(e_3, 1);
	int id_empty_5[9] = {1,1,1,1,1,1,1,1,1};
	MATRIXCOMPARISONWITHARR(e_3, id_empty_5, 9);

	// testing addition, substraction and 
	// multiplication of two matrices
	// a = [1 2 3]
	//     [4 5 6]
	//     [7 8 9]
	matrix* a = createMatrix(3,3,1,2,3,4,5,6,7,8,9);
	assert(a->size == 9);
	assert(a->rowc == 3);
	assert(a->colc == 3);

	// before addMatrix(a, e_3) 
	// a = [1 2 3] e_3 = [1 1 1]
	//     [4 5 6]       [1 1 1]
	//     [7 8 9]       [1 1 1]
	// after
	// b = [2 3  4] 
	//     [5 6  7] 
	//     [8 9 10]
	matrix* b = addMatrix(a, e_3);
	assert(b->size == 9);
	assert(b->rowc == 3);
	assert(b->colc == 3);
	int b_arr[9] = {2,3,4,5,6,7,8,9,10};
	MATRIXCOMPARISONWITHARR(b, b_arr, 9);

	// before subMatrix(b, a) 
	// a = [1 2 3] b = [2 3  4]
	//     [4 5 6]     [5 6  7]
	//     [7 8 9]     [8 9 10]
	// after
	// c = [1 1 1] 
	//     [1 1 1] 
	//     [1 1 1]
	matrix* c = subMatrix(b, a);
	int c_arr[9] = {1,1,1,1,1,1,1,1,1};
	MATRIXCOMPARISONWITHARR(c, c_arr, 9);

	// before multiplyMatrix(a, c) 
	// a = [1 2 3] b =  [2 3  4]
	//     [4 5 6]      [5 6  7]
	//     [7 8 9]      [8 9 10]
	// after
	// d = [ 6  6  6] 
	//     [15 15 15] 
	//     [24 24 24]
	matrix* d = multiplyMatrix(a, c);
	int d_arr[9] = {6,6,6,15,15,15,24,24,24};
	MATRIXCOMPARISONWITHARR(d, d_arr, 9);

	matrix* e = createMatrix(3,3,0,2,1,3,8,1,0,4,1);

	// testing row operations
	// before multiplyRow(b, 1, 2) 
	// 	 1 2 3
	// b = 1[2 3 4]
	//     2[5 6 7]
	//     3[8 9 10]
	// after
	// 	 1 2 3
	// b = 1[4 6 8]
	//     2[5 6 7]
	//     3[8 9 10]
	multiplyRow(b, 1, 2);
	int b_mult_r1[3] = {4,6,8}; 
	int b_idx;
	for (int i = 1; i <= b->colc; i++)
	{
		b_idx = getIndex(b, 1, i);
		int e = b->arr[b_idx];
		assert(e == b_mult_r1[i - 1]);
	}
	// before divideRow(b, 1, 2) 
	// 	 1 2 3
	// b = 1[4 6 8]
	//     2[5 6 7]
	//     3[8 9 10]
	// after
	// 	 1 2 3
	// b = 1[2 3 4]
	//     2[5 6 7]
	//     3[8 9 10]
	divideRow(b, 1, 2);
	int b_mult_r2[3] = {2,3,4}; 
	int b_idx_2;
	for (int i = 1; i <= b->colc; i++){
		b_idx_2 = getIndex(b, 1, i);
		int e = b->arr[b_idx_2];
		assert(e == b_mult_r2[i - 1]);
	}

	// test cases for getIndex
	assert (getIndex(b, 1, 1) == 0);
	assert (getIndex(b, 1, 2) == 1);
	assert (getIndex(b, 1, 3) == 2);
	assert (getIndex(b, 2, 1) == 3);
	assert (getIndex(b, 2, 2) == 4);
	assert (getIndex(b, 2, 3) == 5);
	assert (getIndex(b, 3, 1) == 6);
	assert (getIndex(b, 3, 2) == 7);
	assert (getIndex(b, 3, 3) == 8);

	// test cases for getCol
	assert (getCol(b, 0) == 1);
	assert (getCol(b, 1) == 2);
	assert (getCol(b, 2) == 3);
	assert (getCol(b, 3) == 1);
	assert (getCol(b, 4) == 2);
	assert (getCol(b, 5) == 3);
	assert (getCol(b, 6) == 1);
	assert (getCol(b, 7) == 2);
	assert (getCol(b, 8) == 3);

	assert (getCol(e, 0) == 1);
	assert (getCol(e, 1) == 2);
	assert (getCol(e, 2) == 3);
	assert (getCol(e, 3) == 1);
	assert (getCol(e, 4) == 2);
	assert (getCol(e, 5) == 3);
	assert (getCol(e, 6) == 1);
	assert (getCol(e, 7) == 2);
	assert (getCol(e, 8) == 3);

	// test cases for getRow
	assert (getRow(b, 0) == 1);
	assert (getRow(b, 1) == 1);
	assert (getRow(b, 2) == 1);
	assert (getRow(b, 3) == 2);
	assert (getRow(b, 4) == 2);
	assert (getRow(b, 5) == 2);
	assert (getRow(b, 6) == 3);
	assert (getRow(b, 7) == 3);
	assert (getRow(b, 8) == 3);

	assert (getRow(e, 0) == 1);
	assert (getRow(e, 1) == 1);
	assert (getRow(e, 2) == 1);
	assert (getRow(e, 3) == 2);
	assert (getRow(e, 4) == 2);
	assert (getRow(e, 5) == 2);
	assert (getRow(e, 6) == 3);
	assert (getRow(e, 7) == 3);
	assert (getRow(e, 8) == 3);

	// testing deepCopyMatrixes
	matrix* acopy = createEmptyMatrix(a->rowc, a->colc); 
	copyMatrix(a, acopy);
	compareMatrices(a, acopy);

	// permutation matrices
	int id_1[] = {1,0,0,0,0,1,0,1,0};
	matrix* l = getPermutationMatrix(3, 2, 3);
	MATRIXCOMPARISONWITHARR(l, id_1, 9);
	matrix* q = createMatrix(3,3,1,2,3,4,5,6,7,8,9); 
	matrix* r = createMatrix(4,3,1,2,3,4,5,6,7,8,9,10,11,12); 
	matrix* p = getPermutationMatrix(3, 1, 2);
	swapRows(r, 1, 2);
	multiplyRow(q, 2, 2);
	divideRow(q, 2, 2);

	// freeing the matrices
	freeMatrix(a);
	freeMatrix(b);
	freeMatrix(c);
	freeMatrix(d);
	freeMatrix(e_3);
	freeMatrix(e);
	freeMatrix(p);
	freeMatrix(q);
	freeMatrix(r);
	freeMatrix(l);
	freeMatrix(acopy);

	// augmatrix.h
	// creating a 3x3 matrix
	matrix* m = createMatrix(3,3,1,2,3,4,5,6,7,8,9);
	matrix* n = createMatrix(3,5,1,2,3,4,5,6,7,8,9,\
			10,11,12,13,14,15);
	matrix* o = createEmptyMatrix(10, 10);
	
	// populating the matrix o
	for (int i = 0; i < o->size; i++)
	{
		o->arr[i] = i;
	}

	// creating an augmented matrix
	// augmented matrices are struct is supposed
	// to hold two deep copies of the matrices 
	// passed to the function;
	augmatrix* aug = createAugmentedMatrix(m, n); 
	compareMatrices(m, aug->arr_a);
	compareMatrices(n, aug->arr_b);
	//
	// m = [1 2 3] n = [1  2  3  4  5]
	//     [4 5 6]     [6  7  8  9 10]
	//     [7 8 9]     [11 12 13 14 15]
	// aug = [1 2 3 |  1  2  3  4  5]
	// 	     [4 5 6 |  6  7  8  9 10]
	// 	     [7 8 9 | 11 12 13 14 15]
	//

	aug_addRow(aug, 1, 2, 2);
	int augrow_a_1 = getIndex(aug->arr_a, 1, 1);
	int augrow_a_2 = getIndex(aug->arr_a, 2, 1);
	//
	//       r  1 2 3    4  5  6  7  8
	// aug = 1 [1 2 3 |  1  2  3  4  5]
	//	  	 2 [4 5 6 |  6  7  8  9 10]
	//	  	 3 [7 8 9 | 11 12 13 14 15]
	//
	//after addRow(aug, 1, 2, 2) 
	//       r  1 2 3    4  5  6  7  8
	//aug =  1 [1 2 3 |  1   2   3   4  5]
	//	 	 2 [5 7 9 |  7   9  11  14 15]
	//	 	 3 [7 8 9 | 11  12  13  14 15]
	//
	//
	for (int i = 0; i < aug->arr_a->colc; i++)
	{
		int element_a = 
			aug->arr_a->arr[augrow_a_2];
		assert(element_a  == m->arr[augrow_a_1] + 
				m->arr[augrow_a_2]);
		augrow_a_2++;
		augrow_a_1++;
	}

	aug_subRow(aug, 1, 2, 2);
	int arr_a_ans[] = {-4,-5,-6};
	int arr_b_ans[] = {-6,-7,-8,-9,-10};
	//
	// after subRow(aug, 1, 2, 2) 
	//       r  1 2 3    4  5  6  7  8
	// aug = 1 [1 2 3   |   1   2   3   4  5]
	//	 	 2 [8 10 12 |  12  14  16  18 20]
	//	  	 3 [7 8 9   |  11  12  13  14 15]
	//
	int augrow_a_3 = getIndex(aug->arr_a, 2, 1);
	int augrow_a_4 = getIndex(aug->arr_b, 2, 1);

	for (int i = 0; i < aug->arr_a->colc; i++)
	{
		int element_a = 
			aug->arr_a->arr[augrow_a_3];
		assert(arr_a_ans[i] == element_a);
		augrow_a_3++;
	}

	for (int i = 0; i < aug->arr_b->colc; i++)
	{
		int element_b = 
			aug->arr_b->arr[augrow_a_4];
		assert(arr_b_ans[i] == element_b);
		augrow_a_4++;
	}

	// multiplyByScalar
	// before multiplyMatrix(aug, 2) 
	//        r  1 2 3    4  5  6  7  8
	//  aug = 1 [1 2 3   |   1   2   3   4  5]
	//  	  2 [8 10 12 |  12  14  16  18 20]
	//  	  3 [7 8 9   |  11  12  13  14 15]
	//  after multiplyByScalar(aug, 2)
	//        r  1 2 3        4   5   6   7  8  
	//  aug = 1 [2 4 6    |   2   4   6   8  10]
	//  	  2 [16 20 24 |  24  28  32  36  40]
	//  	  3 [14 16 18 |  22  24  26  28  30]
	aug_multiplyByScalar(aug, 2);
	for (int i = 0; i < aug->arr_a->size; i++)
	{
		assert(aug->arr_a->arr[i] % 2 == 0);
	}
	for (int i = 0; i < aug->arr_b->size; i++)
	{
		assert(aug->arr_b->arr[i] % 2 == 0);
	}

	// addScalarToRow(aug, 1, 2)
	// before addScalarToRow
	//       r  1 2 3        4   5   6   7  8  
	// aug = 1 [2 4 6    |   2   4   6   8  10]
	// 	 	 2 [16 20 24 |  24  28  32  36  40]
	// 	 	 3 [14 16 18 |  22  24  26  28  30]
	// after addScalarToRow
	//       r  1 2 3        4   5   6   7  8  
	// aug = 1 [3 4 5    |   6   7   8   9  11]
	// 		 2 [16 20 24 |  24  28  32  36  40]
	// 		 3 [14 16 18 |  22  24  26  28  30]
	aug_addScalarToRow(aug, 1, 2);
	for (int i = 0; i < aug->arr_a->colc; i++)
	{
		int augrow_a_5 = getIndex(
				aug->arr_a, 1, i + 1);
		assert(aug->arr_a->arr[augrow_a_5] 
				== (m->arr[augrow_a_5]*2)+ 2 );
	}

	for (int i = 0; i < aug->arr_b->colc; i++)
	{
		int augrow_a_5 = getIndex(
				aug->arr_b, 1, i + 1);
		assert(aug->arr_b->arr[augrow_a_5] 
				== (n->arr[augrow_a_5]*2) + 2 );
	}

	// subScalarToRow(aug, 1, 2)
	// before addScalarToRow
	//       r  1 2 3        4   5   6   7  8  
	// aug = 1 [3 4 5    |   6   7   8   9  11]
	// 	 	 2 [16 20 24 |  24  28  32  36  40]
	// 	  	 3 [14 16 18 |  22  24  26  28  30]
	// after addScalarToRow
	//       r  1 2 3        4   5   6   7  8  
	// aug = 1 [2 4 6    |   2   4   6   8  10]
	// 		 2 [16 20 24 |  24  28  32  36  40]
	// 		 3 [14 16 18 |  22  24  26  28  30]
	aug_subScalarFromRow(aug, 1, 2);
	for (int i = 0; i < aug->arr_a->colc; i++)
	{
		int augrow_a_5 = getIndex(
				aug->arr_a, 1, i + 1);
		assert(aug->arr_a->arr[augrow_a_5] 
				== (m->arr[augrow_a_5]*2));
	}
	for (int i = 0; i < aug->arr_b->colc; i++)
	{
		int augrow_a_5 = getIndex(
				aug->arr_b, 1, i + 1);
		assert(aug->arr_b->arr[augrow_a_5] 
				== (n->arr[augrow_a_5]*2));
	}

	freeAugmentedMatrix(aug);

	//get the lower triangular matrix of m
	//	m =   [1 2 3] 
	//	      [4 5 6] 
	//	      [7 8 9]
	//
	// 	ltm = [1 0 0]
	// 	      [4 5 0]
	// 	      [7 8 9]
	matrix* exp_ltm = createMatrix(3,3,1,0,0,4,5,0,7,8,9); 
	matrix* ltm = getLowerTriangularMatrix(m);

	for (int i = 0; i < exp_ltm->size; i++)
	{
		assert(exp_ltm->arr[i] == ltm->arr[i]);
	}

	//get the lower triangular matrix of m
	//	m =   [1 2 3] 
	//	      [4 5 6] 
	//	      [7 8 9]
	//
	// 	ltm = [1 2 3]
	// 	      [0 5 6]
	// 	      [0 0 9]
	matrix* exp_utm = createMatrix(3,3,1,2,3,0,5,6,0,0,9); 
	matrix* utm = getUpperTriangularMatrix(m);
	for (int i = 0; i < exp_utm->size; i++)
	{
		assert(exp_utm->arr[i] == utm->arr[i]);
	}

	matrix* utm_o = getUpperTriangularMatrix(o);
	matrix* ltm_o = getLowerTriangularMatrix(o);

	// freeing up all the matrices
	freeMatrix(m);
	freeMatrix(n);
	freeMatrix(o);
	freeMatrix(exp_ltm);
	freeMatrix(exp_utm);
	freeMatrix(ltm);
	freeMatrix(utm);
	freeMatrix(ltm_o);
	freeMatrix(utm_o);

	return 0;
}
