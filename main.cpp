#include<stdio.h>
#include "recipes.h"

#include<iostream>
#include <cmath>
// #include <array>

using namespace std;


long double f(long double x, long double y) { 
	long double u = 0.1/0.25;
	return -2 * y / ( u * sqrt(1 + pow(y, 2)));
}


int main()
{
    // const size_t N = 100;
	// array<long double, N> x, y;

	int N = 100;
	long double x[N], y[N];

	long double xmin = 0., xmax = 0.5;
	long double h = (xmax - xmin) / (N - 1);
	for (int k = 0; k < N; k++) {
		x[k] = xmin + k*h;
	}

	long double y0 = 1.5;
	long double (*func)(long double, long double) = &f;

	Euler1D(func, y0, N, x, y);

	int k = 4;
	cout << "x[3] = " << x[k] << "\n";
	cout << "y[3] = " << y[k] << "\n";
}