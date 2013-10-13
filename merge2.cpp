#include "merge2.h"

void Solution::merge(int A[], int m, int B[], int n) {
  	int currentA = m - 1;
	int currentB = n - 1;
	int currentMerge = m + n - 1;
	while(currentA>=0 && currentB>=0) {
	  	if(A[currentA] > B[currentB]) {
		  	A[currentMerge] = A[currentA];
			currentMerge--;
			currentA--;
		} else {
		  	A[currentMerge] = B[currentB];
			currentMerge--;
			currentB--;
		}
	}
	if(currentB>=0) 
	  	for(int i = 0; i<= currentB; ++i)
		  	A[i] = B[i];
}
