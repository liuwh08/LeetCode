#include "searchInsert.h"

int binarySearch(int A[], int l, int r, int target) {
	if(l>r)
		return r + 1;
	int m = (l + r)/2;
	if(target == A[m])
		return m;
	if(target > A[m])
		return binarySearch(A, m + 1, r, target);
	return binarySearch(A, l, m - 1, target);
}

int Solution::searchInsert(int A[], int n, int target) {
	return binarySearch(A, 0, n-1, target);
}

