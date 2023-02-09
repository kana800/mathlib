I highly recommend reading **austin henley**'s blog about implementaion of `cos` function.

---

### Approach


> In mathematics, `sine` and `cosine` are trigonometric functions of an angle

Taylors series method can be used to apporximate the `sine` and `cosine` values; A common programming
optimization used is to pre-calculate a table of `sine` or `cosine` values and use the closest value or 
linearly interploate between the values.

> **CORDIC** is algorithm another option for us; It is an iterative method for computing functions
like sine and cosine using only addition, substraction, bit shitfing and with the help of a small
look up table. 

---


### Taylor Series

Taylor Series for `cos(x)` `I = [-1,1]`:

we could write a simple `c` function that would calculate the `cosine` value

```c
// taylor series first 4 terms
double cos(double rad){
	return 1 - ((x*x)/(2)) + 
		((x*x*x*x)/(24)) - 
		((x*x*x*x*x*x)/(720)) + 
		((x*x*x*x*x*x*x*x)/(40320));
}
```

<p style="text-align: center" align="center">
  <img src=".images\cos_taylor_cmp.gif" alt="comparison of cos taylor and numpy cos">
  <br>
  <a>comparison of cos taylor with 4 terms and numpy cos</a>
</p>

Taylor Series for `sin(x)` `I = [-1,1]`:

```c
// taylor series first 4 terms
double sine(double rad){
	return x - ((x*x*x)/6) 
	+ ((x*x*x*x*x)/120) 
	- ((x*x*x*x*x*x*x)/5040)
	+ ((x*x*x*x*x*x*x*x*x)/362880);
}
```

<p style="text-align: center" align="center">
  <img src=".images\sin_taylor_cmp.gif" alt="comparison of sine taylor and numpy sine">
  <br>
  <a>comparison of sine taylor with 4 terms and numpy sin</a>
</p>


Both `sin(x)` and `cos(x)` lose accuracy after the range `[-1,1]`; we can calulate more terms to increase the accuracy further or we can use the fact that `cos` and `sin` repeat itself at `2pi` respectively and calculate `sin`and `cos` using those values. check out Austin Helney's blog about on "implementation on `cos`" for more information of this method; 

### LUTs 

The idea is precomputing `sin` and `cos` values and dropping them into an array.
> Austin Henley used a python script to generate a `c` header file; I will be using that script with some small 
adjustments to generate the header files.

<a style="text-align:center" href="">Generating the Header files</a>


<p style="text-align: center" align="center">
  <img src=".images\sin_lut.gif" alt="comparison of sine taylor, numpy sine and sine lut">
  <br>
  <a>comparison of sine taylor with 4 terms, numpy sine and sine lut</a>
</p>

<p style="text-align: center" align="center">
  <img src=".images\cos_lut.gif" alt="comparison of cos taylor, numpy cos and cos lut">
  <br>
  <a>comparison of cos taylor with 4 terms, numpy cos and cos lut</a>
</p>

### References

- [Implementation of `cos` using `C`](https://austinhenley.com/blog/cosine.html)
- [Sine and Cosine](https://en.wikipedia.org/wiki/Sine_and_cosine)
- [Fastest Implementation of sine, cosine and square root](https://stackoverflow.com/questions/18662261/fastest-implementation-of-sine-cosine-and-square-root-in-c-doesnt-need-to-b)
- [Common Used Taylor Series](https://people.math.sc.edu/girardi/m142/handouts/10sTaylorPolySeries.pdf)
- [How to use Chebyshev Polynomials to approximate `sin` and `cos`](https://math.stackexchange.com/questions/1344627/how-to-use-chebyshev-polynomials-to-approximate-sinx-and-cosx-within-t)
- [This is why you're learning Taylor Series](https://www.youtube.com/watch?v=eX1hvWxmJVE)
