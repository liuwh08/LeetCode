#include "sqrt.h"

int Solution::sqrt(int x) {
  	double r = x;
	double l = 0;
	while(r - l > 0.0000001) {
	  	double mid = (l + r) / 2.0;
		if(mid * mid > x)
		  	r = mid;
		else
		  	l = mid;
	}
	return (int) r;
}
