### Introduction

> Gaussian elimination, also known as row reduction, is an algorithm for solving systems of linear equations. It consists of a sequence of operations performed on the corresponding matrix of coefficients. <sup>[1]</sup>

For example, consider the linear system:

$$
x + 2y + z = 2
$$

$$
3x + 8y + z = 12 
$$

$$
4y + z = 2
$$

We can represent this the system of equation in an augmented matrix:

$$
\begin{bmatrix}
1 & 2 & 1 \\
3 & 8 & 1 \\
0 & 4 & 1 \\
\end{bmatrix}
\begin{bmatrix}
x \\
y \\
z \\
\end{bmatrix} = 
\begin{bmatrix}
2 \\
12 \\
2 \\
\end{bmatrix}
$$

Using the `mathlib` we can make `augmented matrix` :
```c
//augmatrix.h
matrix* a = createMatrix(3,3,1,2,1,3,8,1,0,4,1);
matrix* b = createMatrix(3,1,2,12,2);
augmatrix* aug = createAugmentedMatrix(a, b);
```

The idea is get the **Row Echelon Form** of the Augmented Matrix using **elementary row operations**; 

An augmented matrix is in row-echelon form if <sup>[4]</sup>:

* All nonzero rows are above any rows of zeros.
* Each leading entry of a row is in a column to the right of the leading entries of any row above it.
* Each leading entry of a row is equal to 1

$$
\begin{bmatrix}
1 & 2 & 1 \\
3 & 8 & 1 \\
0 & 4 & 1 \\
\end{bmatrix} \to
\begin{bmatrix}
1 & 2 & 1 \\
0 & 2 & -2 \\
0 & 0 & 5 \\
\end{bmatrix}
$$

### Pivots Pivots Pivots

> A pivot position in a matrix is the location of a leading entry in the row-echelon form of a matrix. A pivot column is a column that contains a pivot position. <sup>[4]</sup>

For example: In our previous matrix,

$$
\begin{bmatrix}
1 & 2 & 1 \\
3 & 8 & 1 \\
0 & 4 & 1 \\
\end{bmatrix}
$$

The pivot position were $A_{11}$, $A_{22}$; pivots we are selecting cannot be  zero; If there is a pivot with zero we can always exchange the row.

### Algorithm

1. Starting from the left, find the first non-zero column. This is the first *pivot position*. Switch rows if needed to place a non-zero number in first pivot position.
2. Use row operations to make the entries below the first pivot position to be equal to zero.
3. Keep repeating step `1` and `2` till we modify all the rows.
4. Make the leading entries $1$ by dividing itself and other elements of the row


### References

1. [Gaussian Elimination](https://en.wikipedia.org/wiki/Gaussian_elimination)
2. [Linear Optimization:Pivot selection rules](https://www.wiwi.uni-kl.de/bisor-orwiki/Linear_optimization:_Pivot_selection_rules_3)
3. [My Note's On Gaussian Elimination](https://kannna.xyz/knowledge/courses/linearalgebra/linearalgebramoc)
4. [Gaussian Elimination](https://math.libretexts.org/Courses/Community_College_of_Denver/MAT_2562_Differential_Equations_with_Linear_Algebra/11%3A_Systems_of_Equations/11.03%3A_Gaussian_Elimination)

[1]:https://en.wikipedia.org/wiki/Gaussian_elimination
[4]:https://math.libretexts.org/Courses/Community_College_of_Denver/MAT_2562_Differential_Equations_with_Linear_Algebra/11%3A_Systems_of_Equations/11.03%3A_Gaussian_Elimination
