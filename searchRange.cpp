#include "searchRange.h"

using namespace std;

int binaryserach(int A[], int l, int r, int target) {
	if(l>r)
		return -1;
	int m = (l + r)/2;
	if(A[m] == target)
		return m;
	if(target < A[m])
		return binaryserach(A, l, m - 1, target);
	else
		return binaryserach(A, m + 1, r, target);
}

vector<int> Solution::searchRange(int A[], int n, int target){
	int index = binaryserach(A, 0, n - 1, target);
	vector<int> res;
	if(index == -1) {
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	int forward = index, backward = index;
	while((forward<n-1)&&(A[forward + 1] == target))
	       forward++;
	while((backward>0)&&(A[backward - 1] == target))
		backward--;
	res.push_back(backward);
	res.push_back(forward);
	return res;
}
