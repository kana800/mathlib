### Matrices

> This library provides the ability to do **basic** matrix calculations; [MIT **Linear-Algebra** Course](https://ocw.mit.edu/courses/res-18-010-a-2020-vision-of-linear-algebra-spring-2020/)


The `matrix` datastructure holds all the key components to the matrix;

```c
typedef struct matrix_ {
	float* matrixptr; // pointer to the matrix
	int size; // size of the matrix
	int row; // row count
	int col; // col count
	float** rowmatrix; // pointer to the row in the matrix
	float** colmatrix; // pointer to the columns in the matrix
} matrix;
```

The `matrix` is created as a continuous `1D` array and `float** rowmatrix` and `float** colmatrix` is used
to keep in track of the rows and columns in the given matrix.

<img style="align:center;" src="https://latex.codecogs.com/png.image?%5Cdpi%7B110%7DA%20=%20%5Cbegin%7Bbmatrix%7D1%20&%202%20&%203%20%5C%5C4%20&%205%20&%206%20%5C%5C7%20&%208%20&%209%20%5C%5C%5Cend%7Bbmatrix%7D">

The `float* matptr` for the above `matrix A` would look something like this,



#### Accessing Data Of A Matrix

You can easily iterate over the matrix since we know the number of `rows` and `cols` in a matrix;

```c
```
