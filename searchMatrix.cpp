#include "searchMatrix.h"

using namespace std;

int twoDToOneD(const vector<vector<int> > &matrix, int index) {
	int m = matrix[0].size();
	int i = index/m;
	int j = index % m;
	return matrix[i][j];
}

bool Solution::searchMatrix(vector<vector<int> > &matrix, int target) {
  	int l = 0;
	int n = matrix.size();
	if(n == 0)
	  	return false;
	int m = matrix[0].size(), r = m*n - 1;
	while(l<=r) {
	  	int mid = (l + r)/2;
		int entry = twoDToOneD(matrix, mid);
		if(entry == target)
		  	return true;
		if(entry>target) 
		  	r = mid - 1;
		if(entry<target)
		  	l = mid + 1;
	}
	return false;
}
