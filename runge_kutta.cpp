#include<stdio.h>
#include "recipes.h"

void RungeKutta(
	long double (*func)(long double, long double),		// right side function
	long double y0,										// initial condition
	int N,												// array size
	long double* x,					 					// domain boundaries
	long double* y										// resulting array
) 
{
	long double h, k1, k2, k3, k4;

	y[0] = y0;
	for (int k = 0; k < N-1; k++) {
		h = x[k+1] - x[k];

        k1 = (*func)( x[k], y[k] );
        k2 = (*func)( x[k] + h/2, y[k] + h*k1/2 );
        k3 = (*func)( x[k] + h/2, y[k] + h*k2/2 );
        k4 = (*func)( x[k] + h, y[k] + h*k3 );
        
		y[k + 1] = y[k] + h/6 * (k1 + 2*k2 + 2*k3 + k4);
	}
}