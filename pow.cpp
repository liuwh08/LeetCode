#include "pow.h"

double pow_positive(double x, int n) {
	if(n==0)
		return 1.0;
	if(n==1)
		return x;
	if(n%2 == 1)
		return x*pow_positive(x, n-1);
	double tmp = pow_positive(x, n/2);
	return tmp*tmp;
}



double Solution::pow(double x, int n) {
	if(n>=0)
		return pow_positive(x, n);
	else
		return 1/pow_positive(x, -n);
}

