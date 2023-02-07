#ifndef TRIG_H
#define TRIG_H

#include <stdio.h>

double cos_taylor(double x) {
	/*summary: return the cos value
	args:
		double x -> radian value
	ret:
		appopriate cosine value
	*/
	return 1 - ((x * x) / (2)) +
		((x * x * x * x) / (24)) -
		((x * x * x * x * x * x) / (720)) +
		((x * x * x * x * x * x * x * x) / (40320));
}

double sine_taylor(double x) {
	/*summary: return the sine value
	args:
		double x -> radian value
	ret:
		appopriate sine value
	*/
	return x - ((x * x * x) / 6)
		+ ((x * x * x * x * x) / 120)
		- ((x * x * x * x * x * x * x) / 5040)
		+ ((x * x * x * x * x * x * x * x * x) / 362880);
}
#endif // !TRIG_H
