> This folder contains all the necessary libraries to build a module

<h3 align="center">Libraries</h3>


### Table Of Content

- [coordinate](#coordinate)
- [matrices](#matrices)
	- [creation of a matrix](#creationofamatrix)
	- [accessing data of a matrix](#accessingdataofamatrix)

---

### Matrices

> This library provides the ability to do **basic** matrix calculations; [MIT **Linear-Algebra** Course](https://ocw.mit.edu/courses/res-18-010-a-2020-vision-of-linear-algebra-spring-2020/)

#### Creation Of A Matrix

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

The matrix is created as a continuous `1D` array and `int* rowmatrix` and `int* colmatrix` is used
to keep in track of the rows and columns in the given matrix;

<insert image of matrix_ custom datastructure here>


#### Accessing Data Of A Matrix

You can easily iterate over the matrix since we know the number of `rows` and `cols` in a matrix;

```c
```

---

### Coordinate

The coordinate library is capable of handling cartesian coordinate system and the polar coordinate system;
The *test cases* for the coordinate library is in [tests/coordtest]().


### Trigonometry

> A common programming optimization, used especially in 3D graphics, is to pre-calculate a table of sine values, for example one value per degree, 
then for values in-between pick the closest pre-calculated value, or linearly interpolate between the 2 closest values to approximate it. 
This allows results to be looked up from a table rather than being calculated in real time. 
With modern CPU architectures this method may offer no advantage.[citation needed]
**The CORDIC algorithm is commonly used in scientific calculators.**

### References

