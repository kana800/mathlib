### Representation

"How am I going to represent the matrix in code?" Lets take the *Identity Matrix* below as an example:

$$
\begin{bmatrix}
1 & 0 & 0\\
0 & 1 & 0\\
0 & 0 & 1\\
\end{bmatrix}
$$
- can I represent them in one array like this, `int arr[matsize] = {1,0,0,0,1,0,0,0,1};`.  The probably here is this a variable length array, `matsize` is not an constant expression (`C90` doesn't  allow *VLA*s but can be used in `C99` ) I can always use *dynamic array allocation* but if i am doing that I need worry about garbage collection...
- what if i represent each *row* in an array or each *col* in an array (*row-major order* or *col-major order*)
```c
[[1,0,0],[0,1,0],[0,0,1]] // rows
[[1,0,0],[0,1,0],[0,0,1]] // cols
```
-  If I am trying this approach I have to deal with lot of arrays;  Represent the matrix in *row* form or *col* form would help me to draw the *row* and *col* pictures of the matrix.
- In `c`, multidimensional arrays are stores in the *row-major order*.<sup>[1]</sup> 

$$
A = \begin{bmatrix}
a_{11} & a_{12} & a_{13}\\
a_{21} & a_{22} & a_{23}\\
a_{31} & a_{32} & a_{33}\\
\end{bmatrix}
$$

- In the above matrix, *row-major order* would be : `a11 a12 a13 a21 a22 a23 a31 a32 a33`
- In the above matrix, *col-major order*  would be:  `a11 a21 a31 a12 a22 a32 a13 a23 a33`
- We will discuss more about this in the next section; when we are talking about *indexing*

> In numpy, the arrays consist of two major components: the raw array data and the information about the raw array data. The raw array data or the data buffer is a *contiguous* block of memory containing fixed-sized data items. <sup>[2]</sup>

Okay, Matrix can be represented a *contiguous* array, The matrix $A$ will be `int* arr = {a11, a12, a13, a21, ... , a33}`;

In our library the matrix library is represented in this structure:
```c
typedef struct __matrix__{
	int* arr; // pointer to array 
	int size; // size of the matrix
	int rowc; // row count
	int colc; // col count
} matrix;
```

### Indexing 

You can use `getIndex(matrix* a, int r, int c)` to obtain the index of matrix; Example matrix $A$ is a $3 \times 3$ matrix where each element represent the `index` of the array in the `matrix.arr` structure; 

$$
\begin{bmatrix}
0 & 1 & 2 \\
3 & 4 & 5 \\
6 & 7 & 8 \\
\end{bmatrix}
$$

`getIndex` uses following equation to obtain the index of the equation;

$$
\mathbf{colc(r - 1) + (c - 1)}
$$

### Relationship of `rows` and `cols`

If you notice in the above matrix example: 
- column $1$ got the indexes $0,1,3$ 
- column $2$ got the indexes $1,4,7$ 
- column $3$ got the indexes $2,5,8$

The main idea to get from this is that each is incremented by $3$ which is the `col size`, we can make a more generic equation out of this, the below equation can be used to obtain the row index of each element: 

$$
\mathbf{row_{i,j}} = 3n - \mathbf{(c - j + 1)}
$$

- $c$ stand for the number of columns
- $j$ stand for column number

For example to obtain index of elements in first column of our example matrix we can replace $j$ with $1$ and equation will be

$$
\mathbf{row_{i,1}} = 3n - \mathbf{(3 - 1 + 1)} \to 3n - 3
$$

`getCol` and `getRow` will allow us to get the row or the col value that is represented by the index;

---

- [Introduction](#introduction)
- [Creation Of Matrix]()
    - [Identity Matrix]()
    - [Empty Matrix]()
- [Accessing Values From A Matrix]()
- [Performing Arithmetic Operations]()
    - [Addition]()
    - [Substraction]()
    - [Multiplication]()
- [Obtaining Inverses]()

### Introduction

The `matrix` datastructure holds all the key components to the matrix;

```c
typedef struct __matrix__{
	int* arr;
	int size; // size of the matrix
	int rowc; // row count
	int colc; // col count
} matrix;
```

### Creation Of Matrix

To create matrix matrix you can use `createMatrix` function;

```c
// creation of 2x2 matrix
matrix * m = createMatrix(2,2,0,1,2,3);
```

You should know that the you have to input the `entries` of the matrix in the *row-major* order; 

For example: 
``` 
      0 1
m = 0[a,b]
    1[c,d]

matrix *m = createMatrix(2,2,a,b,c,d);
```

#### Identity Matrix

To create an Identity matrix you can use the `createIdentityMatrix` function;

```c
// creation of identity matrix 3x3 matrix
matrix *i = createIdentityMatrix(3);
```

#### Empty Matrix

To create an Empty matrix you can use the `createEmptyMatrix` function; This will return zero intialized matrix 

```c
// creation of zero-initialised 3x3 matrix
matrix *z = createEmptyMatrix(3,3);
```

### Accessing Values From A Matrix

To access the values you can use the `getRowIndex` function or `getColIndex` function;

For example: 
```
// 3x3 matrix
m = [1,2,3]
    [4,5,6]
    [7,8,9]
```

- `rowindex` : `index` of where a row starts; In above `3x3` matrix rows indexes will be :

```
1->[1,2,3]
2->[4,5,6]
3->[7,8,9]
```

- `colindex` : `index` of where a column starts; In the above `3x3` matrix col indexes will be :

```
 1 2 3
 | | |
[1,2,3]
[4,5,6]
[7,8,9]
```

> [Read More About This In Docs]()

### Performing Arithmetic Operations

#### Addition 

For addition of matrices you can use the following function:

```
addMatrix(matrix* a, matrix* b);
```

#### Substraction

For substraction of matrices you can use the following function:

```
subMatrix(matrix* a, matrix* b);
```

#### Multiplication

For multiplication of matrices you can use the following function:

```
multiplyMatrix(matrix* a, matrix* b);
```

### Augmented Matrices

Augmented Matrices have a special structure because we are working with `2` matrices;

```c
typedef struct __augmatrix__ {
    matrix* a;
    matrix* b;
} augmatrix;
```

To create a augmented matrix you can use the function `createAugmentedMatrix(matrix* a, matrix* b)`;

For example:
```c
/*
A = [1 3 2]
    [2 0 1]
    [5 2 2]
*/
matrix *a = createMatrix(3,3,1,3,2,2,0,1,5,2,2);
/*
B = [4]
    [3]
    [1]
*/
matrix *b = createMatrix(3,1,4,3,1);
augmatrix* ab = createAugmentedMatrix(a,b);
```


---

### References
- [Row and Col Major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order)
- [Internal organization of NumPy arrays](https://numpy.org/devdocs/dev/internals.html)
- [MatLib Doc's](https://github.com/kana800/mathlib)

[1]:https://en.wikipedia.org/wiki/Row-_and_column-major_order
[2]:https://numpy.org/devdocs/dev/internals.html
