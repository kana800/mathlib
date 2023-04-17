#ifndef AUGMATRIX_H
#define AUGMATRIX_H

#include "matrix.h"

typedef struct __augmatrix__ {
	/*augmented matrix*/
	matrix* arr_a; // pointer to matrix a
	matrix* arr_b; // pointer to matrix b
} augmatrix;

void freeAugmentedMatrix(augmatrix* m){
	/*summary: free the augmented matrix 
	 * from the heap
	 *args:augmatrix* m -> pointer to to a matrix;
	 *ret: none*/
	matrix* a = m->arr_a;
	matrix* b = m->arr_b;

	free(m);
	freeMatrix(a);
	freeMatrix(b);
	return;
}

augmatrix* createAugmentedMatrix(matrix* a, matrix* b){
	/*summary: create an augmented matrix
	 * by appending the columns of two given matrices
	 *args:
		matrix* a -> matrix 1
		matrix* b -> matrix 2
		a = [1 3 2] b=[4]
		    [2 0 1]   [3]
		    [5 2 2]   [1]
		augmented = [1 3 2 |4]
			    [2 0 1 |3]
			    [5 2 2 |1]
	 *ret: matrix * -> pointer to a matrix*/
	if (a->rowc != b->rowc){
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

void multiplyByScalar(augmatrix* a, int s){
	/*summary: inplace multiply augmented
	 * matrix with a scalar value;
	 *args: augmatrix *a -> augmented matrix 
	 	int s -> scalar value
	 *return: NIL*/
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;
	for (int i = 0; i < mat_a->size ; i++){
		mat_a->arr[i] *= s; 
	}
	for (int i = 0; i < mat_a->size ; i++){
		mat_b->arr[i] *= s; 
	}
}


void addScalarToRow(augmatrix* a, int row, int s){
	/*summary: add a scalar to a given row;
	 *args: augmatrix *a -> augmented matrix 
	 	int row -> row count
	 	int s -> scalar value
	 *return: NIL*/
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if (row > mat_a->rowc){
		fprintf(stderr,"Row Count is High\n");
		return;
	}
	
	int row_a = getIndex(mat_a,0,row);
	int row_b = getIndex(mat_b,0,row);

	for (int i = 0; i < mat_a->colc; i++){
		mat_a->arr[row_a] += s; 
		row_a += 1;
	}

	for (int i = 0; i < mat_b->colc; i++){
		mat_b->arr[row_b] += s; 
		row_b += 1;
	}

	return;
}

void subScalarFromRow(augmatrix* a, int row, int s){
	/*summary: substract a scalar from a given row;
	 *args: augmatrix *a -> augmented matrix 
	 	int row -> row count
	 	int s -> scalar value
	 *return: NIL*/
	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if (row > mat_a->rowc){
		fprintf(stderr,"Row Count is High\n");
		return;
	}
	
	int row_a = getIndex(mat_a,0,row);
	int row_b = getIndex(mat_b,0,row);

	for (int i = 0; i < mat_a->colc; i++){
		mat_a->arr[row_a] -= s; 
		row_a += 1;
	}

	for (int i = 0; i < mat_b->colc; i++){
		mat_b->arr[row_b] -= s; 
		row_b += 1;
	}
	return;
}

void addRow(augmatrix* a, int r1, int r2, int r3){
	/*summary: add two rows together
	 *args: augmatrix* a -> augmented matrix 
	 	int r1 -> row #1 
		int r2 -> row #2
		int r3 -> row #3
	 *	r3 = r1 + r2;
	 *ret: NIL*/

	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if ((r1 > mat_a->rowc) ||
		(r2 > mat_a->rowc) ||
		(r3 > mat_a->rowc)){
		fprintf(stderr, "Row Count is High\n");
		return;
	}

	// get the starting indexes of all the rows
	int row_a_r1 = getIndex(mat_a, 0, r1); 
	int row_a_r2 = getIndex(mat_a, 0, r2); 
	int row_a_r3 = getIndex(mat_a, 0, r3); 
	
	int row_b_r1 = getIndex(mat_b, 0, r1); 
	int row_b_r2 = getIndex(mat_b, 0, r2); 
	int row_b_r3 = getIndex(mat_b, 0, r3); 


	for (int i = 0; i < mat_a->colc; i++){
		mat_a->arr[row_a_r3] = 
			mat_a->arr[row_a_r1] + 
			mat_a->arr[row_a_r2]; 
		row_a_r1 += 1; 
		row_a_r2 += 1; 
		row_a_r3 += 1; 
	}

	for (int i = 0; i < mat_b->colc; i++){
		mat_b->arr[row_b_r3] = 
			mat_b->arr[row_b_r1] + 
			mat_b->arr[row_b_r2]; 
		row_b_r1 += 1; 
		row_b_r2 += 1; 
		row_b_r3 += 1; 
	}

	return;
}

void subRow(augmatrix* a, int r1, int r2, int r3){
	/*summary: add two rows together
	 *args: augmatrix* a -> augmented matrix 
	 	int r1 -> row #1 
		int r2 -> row #2
		int r3 -> row #3
	 *	r3 = r1 - r2;
	 *ret: NIL*/

	matrix* mat_a = a->arr_a;
	matrix* mat_b = a->arr_b;

	if ((r1 > mat_a->rowc) ||
		(r2 > mat_a->rowc) ||
		(r3 > mat_a->rowc)){
		fprintf(stderr, "Row Count is High\n");
		return;
	}

	// get the starting indexes of all the rows
	int row_a_r1 = getIndex(mat_a, 0, r1); 
	int row_a_r2 = getIndex(mat_a, 0, r2); 
	int row_a_r3 = getIndex(mat_a, 0, r3); 
	
	int row_b_r1 = getIndex(mat_b, 0, r1); 
	int row_b_r2 = getIndex(mat_b, 0, r2); 
	int row_b_r3 = getIndex(mat_b, 0, r3); 

	for (int i = 0; i < mat_a->colc; i++){
		mat_a->arr[row_a_r3] = 
			mat_a->arr[row_a_r1] - 
			mat_a->arr[row_a_r2]; 
		row_a_r1 += 1; 
		row_a_r2 += 1; 
		row_a_r3 += 1; 
	}

	for (int i = 0; i < mat_b->colc; i++){
		mat_b->arr[row_b_r3] = 
			mat_b->arr[row_b_r1] - 
			mat_b->arr[row_b_r2]; 
		row_b_r1 += 1; 
		row_b_r2 += 1; 
		row_b_r3 += 1; 
	}

	return;
}

#endif // !AUGMATRIX_H
