#include "rotate.h"

using namespace std;

void Solution::rotate(vector<vector<int> > &matrix) {
	int n = matrix.size();
	int m = n;
	if(n == 0)
		return;
	int mid = (n % 2==1)? n/2 + 1:n/2;
	for (int i = 0; i < mid; ++i)
	{
		for (int j = 0; j < n/2; ++j)
		{
			int tmp1 = matrix[i][j];
			int tmp2 = matrix[n-1-j][i];
			int tmp3 = matrix[j][n-1-i];
			int tmp4 = matrix[n-1-i][m-1-j];
			matrix[n-1-i][m-1-j] = tmp3;
			matrix[i][j] = tmp2;
			matrix[n-1-j][i] = tmp4;
			matrix[j][n-1-i] = tmp1;
		}
	}
	return;
}
