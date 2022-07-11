#include<stdio.h>
#include "recipes.h"


void Euler1D(
	long double (*func)(long double, long double),		// right side function
	long double y0,										// initial condition
	int N,												// array size
	long double* x,					 					// domain boundaries
	long double* y										// resulting array
) 
{
	long double h;

	y[0] = y0;
	for (int k = 0; k < N-1; k++) {
		h = x[k+1] - x[k];
		y[k + 1] = y[k] + h * (*func)( x[k], y[k] );
	}
}