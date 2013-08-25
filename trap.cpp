#include "trap.h"

int Solution::trap(int A[], int n) {
	int* minMax = new int[n];
	int max_height = A[0];
	for (int i = 0; i < n; ++i)
	{
		minMax[i] = max_height;
		if(max_height<A[i])
			max_height = A[i];
	}

	max_height = A[n-1];
	for (int i = n - 1; i >= 0; i--)
	{
		if(minMax[i]>max_height)
			minMax[i] = max_height;
		if(max_height<A[i])
			max_height = A[i];
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if(minMax[i]>A[i])
			sum += minMax[i] - A[i];
	}
	return sum;
}
