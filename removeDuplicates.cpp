#include "removeDuplicates.h"


int Solution::removeDuplicates(int A[], int n) {
	int i = 1, j = 1;
	if(n==1)
		return 1;
	if(n==0)
		return 0;
	while(j<n) {
		while((A[j] == A[j-1])&&(j<n))
			j++;
		if(j<n) {
			A[i++] = A[j++];
		}
	}
	return i;
}

