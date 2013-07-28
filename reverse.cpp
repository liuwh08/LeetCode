#include "reverse.h"


int Solution::reverse(int x) {
	bool neg = false;
	if(x<0){ neg = true; x = -x;}
	int sum = 0;
	while(x > 0) {
		sum = sum * 10;
		int last = x % 10;
		sum += last;
		x = x/10;
	}
	if(neg)
		sum = -sum;
	return sum;
}
