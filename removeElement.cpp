#include "removeElement.h"

int Solution::removeElement(int A[], int n, int elem) {
	int i = 0, j = 0;
	if(n==0)
		return 0;
	while(j<n) {
		if(A[j]==elem){
			j++;
			continue;
		}
		A[i++] = A[j++];
	}
	return i;
}

