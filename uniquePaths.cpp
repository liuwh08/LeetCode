#include "uniquePaths.h"
#include <vector>

using namespace std;

int Solution::uniquePaths(int m, int n) {
	vector<vector<int> > DP(m, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		DP[m-1][i] = 1;
	}
	for (int i = 0; i < m; ++i)
	{
		DP[i][n-1] = 1;
	}

	for (int i = n-2; i >=0; i--)
	{
		for (int j = m - 2; j >= 0 ; j--)
		{
			DP[j][i] = DP[j + 1][i] + DP[j][i+1];
		}
	}
	return DP[0][0];
}


