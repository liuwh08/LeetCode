#include "search.h"
#include <iostream>


int Solution::search(int A[], int n, int target) {
	int l = 0, r = n - 1;
	while(l<=r) {
		int m = (l + r)/2;
		if(A[m] == target)
			return m;
		if(A[m] < A[l]) {
			if(target<A[m])
				r = m - 1;
			if(target>=A[l])
				r = m - 1;
			if(target>A[m] && target<A[l])
				l = m + 1;
		}
		if(A[m] >= A[l]) {
			if(target<A[m] && target>=A[l])
				r = m - 1;
			if(target>=A[m] || target<A[l])
				l = m + 1;
		}
		std::cout<<l<<' '<<r<<std::endl;
	}
	return -1;
}


