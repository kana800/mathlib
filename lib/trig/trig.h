#ifndef TRIG_H
#define TRIG_H

#include <stdio.h>
#include "costable_0_01.h"
#include "sintable_0_01.h"


#define CONST_2PI 6.28318530718
#define modd(x, y) ((x) - (int)((x) / (y)) * (y))

double absd(double a) {
	*((unsigned long *)&a) &= ~(1UL << 63); 
	return a; 
}

double cos_taylor(double x);
double sine_taylor(double x);

double cos_table_0_01(double x);
double sin_table_0_01(double x);

#endif // !TRIG_H
