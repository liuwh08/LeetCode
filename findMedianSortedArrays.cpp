#include "findMedianSortedArrays.h"
#include <algorithm>
#include <iostream>

using namespace std;

double Solution::findMedianSortedArrays(int A[], int m, int B[], int n) {
	if ((m+n)%2 == 1)
	{
		return GetKthStat(A, m, B, n, (m + n)/2 + 1);
	}
	else
	{
		//cout<< GetKthStat(A, m, B, n, (m + n)/2)<<' '<<GetKthStat(A, m, B, n, (m + n)/2 + 1)<<endl;
		return (GetKthStat(A, m, B, n, (m + n)/2) + GetKthStat(A, m, B, n, (m+n)/2 + 1))/2.0;
	}
}

int GetKthStat(int A[], int m, int B[], int n, int k) {
	if (m<=0)
	{
		return B[k - 1];
	}
	if (n<=0)
	{
		return A[k - 1];
	}
	if (k<=1)
	{
		return min(A[0], B[0]);
	}
	int mid1 = A[m/2], mid2 = B[n/2];
	if (mid1>mid2)
	{
		if (k<=m/2+n/2+1)
		{
			return GetKthStat(A, m/2, B, n, k);
		}
		else
		{
			return GetKthStat(A, m, B + n/2 + 1, n - (n/2 + 1), k - (n/2 + 1));
		}
	}
	else
	{
		if (k<=m/2+n/2+1)
		{
			return GetKthStat(A, m, B, n/2, k);
		}
		else
		{
			return GetKthStat(A + m/2 + 1, m - (m/2 + 1), B, n, k - (m/2 + 1));
		}
	}
}

