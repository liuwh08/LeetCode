#include "jump.h"

int Solution::jump(int A[], int n) {
	if(n==1)
		return 0;
	int start = 0, end = 0;
	int steps = 0;
	while(end<n) {
		int max_length = 0;
		steps++;
		for (int i = start; i <=end; i++)
		{
			if( i + A[i] >= n - 1)
				return steps;
			if( i + A[i] > max_length)
				max_length = i + A[i];
		}
		start = end + 1;
		end = max_length;
	}
	return steps;
}
