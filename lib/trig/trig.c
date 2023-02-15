#include "trig.h"

double cos_taylor(double x){
	/*summary: return the cos value
	args:
		double x -> radian value
	ret:
		double
	*/
	return 1 - ((x * x) / (2)) +
		((x * x * x * x) / (24)) -
		((x * x * x * x * x * x) / (720)) +
		((x * x * x * x * x * x * x * x) / (40320));
}

double sine_taylor(double x){ 
	/*summary: return the sine value
	args:
		double x -> radian value
	ret:
		double
	*/
	return x - ((x * x * x) / 6)
		+ ((x * x * x * x * x) / 120)
		- ((x * x * x * x * x * x * x) / 5040)
		+ ((x * x * x * x * x * x * x * x * x) / 362880);
}

double cos_table_0_01(double x){
	/*summary: return the cosine values
	code for this function is obtained
	from austin henley's implementation 
	of cos
	args: 
		double x -> radian values
	ret:
		double
	*/
	x = absd(x);
	x = modd(x, CONST_2PI);
	return costable_0_01[(int)(x*100 + 0.5)];
}

double sin_table_0_01(double x){
	/*summary: return the sine values
	code for this function is obtained
	from austin henley's implementation 
	of sin
	args: 
		double x -> radian values
	ret:
		double
	*/
	double org = x;
	x = absd(x);
	x = modd(x, CONST_2PI);
	double ans = sintable_0_01[(int)(x*100 + 0.5)];
	if (org < 0) {
		return (double)(-1 * ans);
	}
	return ans;
}
