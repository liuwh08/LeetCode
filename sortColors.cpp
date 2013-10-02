#include "sortColors.h"
#include <algorithm>

void Solution::sortColors(int A[], int n) {
  	int redIndex = 0, blueIndex = n - 1;
	int i = 0;
	while(i<blueIndex + 1) {
	  	if(A[i] == 0) {
		  	std::swap(A[redIndex], A[i]);
			i++;
			redIndex++;
			continue;
		}
		if(A[i] == 2) {
		  	std::swap(A[blueIndex], A[i]);
			blueIndex--;
			continue;
		}
		i++;
	}
}
