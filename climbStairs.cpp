#include "climbStairs.h"

int Solution::climbStairs(int n) {
  	int* s = new int[n+1];
	if(n<2)
	  	return 1;
	s[0] = 1;
	s[1] = 1;
	for (int i = 2; i < n + 1; ++i)
	{
	  	s[i] = s[i-2] + s[i-1];
	}
	delete[] s;
	return s[n];
}
