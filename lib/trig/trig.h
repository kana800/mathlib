#ifndef TRIG_H
#define TRIG_H

#include <stdio.h>

#define CONST_2PI 6.28318530718
#define modd(x, y) ((x) - (int)((x) / (y)) * (y))

double absd(double a);

double cos_taylor(double x);
double sine_taylor(double x);

double cos_table_0_01(double x);
double sin_table_0_01(double x);

#endif // !TRIG_H
