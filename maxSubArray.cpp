#include "maxSubArray.h"

int Solution::maxSubArray(int A[], int n) {
	int* max_Array = new int[n];
	int max_sum;
	if(n==0)
		return 0;
	max_Array[0] = A[0]>0? A[0]:0;
	max_sum = A[0];
	for (int i = 1; i < n; ++i)
	{
		max_Array[i] = (max_Array[i-1] + A[i] >0)? max_Array[i-1]+A[i] : 0;
		max_sum = (max_Array[i-1] + A[i]>max_sum)? max_Array[i-1]+A[i]:max_sum;
	}
	return max_sum;
}
