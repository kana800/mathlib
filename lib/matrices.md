### Matrices

> This library provides the ability to do **basic** matrix calculations; [MIT **Linear-Algebra** Course](https://ocw.mit.edu/courses/res-18-010-a-2020-vision-of-linear-algebra-spring-2020/)


The `matrix` datastructure holds all the key components to the matrix;

```c
typedef struct matrix_ {
	elementcontainer* matrixptr; // pointer to the matrix
	int size; // size of the matrix
	int row; // row count
	int col; // col count
} matrix;
```

`elementcontainer` contains the `elements` which holds the `data` of the matrix. `elementcontainer` will imitate a **double-linked list**, we could have used a **simple array** instead of a **linked-list** which would reduce the *complexity* of code.

```c
typedef struct matrix_ {
	element* d; // matrix information
	element* next; // pointer to the next element
} elementcontainer;

typedef struct data_ {
	int row; // row number
	int col; // col number
	float d; // data point
	int index; // normal index number
} element;
```


#### Accessing Data Of A Matrix

You can easily iterate over the matrix since we know the number of `rows` and `cols` in a matrix;

```c
```
