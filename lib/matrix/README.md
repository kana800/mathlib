### Matrices

> This library provides the ability to do **basic** matrix calculations; [MIT **Linear-Algebra** Course](https://ocw.mit.edu/courses/res-18-010-a-2020-vision-of-linear-algebra-spring-2020/). You can check up the write ups of certain topics on this module on [garden]()

### Map-Of-Content

- [Building]()
- [Introduction](###Introduction)
- [Creation Of Matrix]()
    - [Identity Matrix]()
    - [Empty Matrix]()
- [Accessing Values From A Matrix]()
- [Performing Arithmetic Operations]()
    - [Addition]()
    - [Substraction]()
    - [Multiplication]()
- [Obtaining Inverses]()


### Building

- To build matrix library: 
```bash
make matrix
```
- To build test cases:
```bash
make mattest
```

The files and the libraries will be built on the `build/matrix/` directory;


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
