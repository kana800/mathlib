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

### References
- [Row and Col Major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order)
- [Internal organization of NumPy arrays](https://numpy.org/devdocs/dev/internals.html)
- [MatLib Doc's](https://github.com/kana800/mathlib)

[1]:https://en.wikipedia.org/wiki/Row-_and_column-major_order
[2]:https://numpy.org/devdocs/dev/internals.html
