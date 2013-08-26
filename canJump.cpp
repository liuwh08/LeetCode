#include "canJump.h"

bool Solution::canJump(int A[], int n) {
	if(n==1) return true;
	int start = 0, end = 0;
	while((start<=end)&&(end<n)){
		int max = end;
		for (int i = start; i <= end; ++i)
		{
			if(A[i] + i > max){
				max = A[i] + i;
			}
		}
		if(max>=n-1)
			return true;
		start = end + 1;
		end = max;
	}
	return false;
}
