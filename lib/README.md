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

The `matrix` is created on the **heap** as a continuous chunk of data; 

```c
int *mptr = malloc(sizeof(int) * (row * col))
```

The matrix `structure` holds information like `size`, `row` and `col` count.
To help the counting and travesing the matrix

Once you have created the matrix; you have to **release** it using the function `freeMatrix`;

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

