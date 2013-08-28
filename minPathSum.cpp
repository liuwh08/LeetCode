#include "minPathSum.h"

using namespace std;

int Solution::minPathSum(vector<vector<int> > &grid) {
	int m = grid.size(), n = grid[0].size();
	vector<vector<int> > DP(m, vector<int>(n, 0));
	DP[m-1][n-1] = grid[m-1][n-1];
	for(int i = m-2; i>=0; i--) {
		DP[i][n-1] = DP[i+1][n-1] + grid[i][n-1];
	}

	for (int i = n - 2; i >= 0 ; i--)
	{
		DP[m-1][i] = DP[m-1][i+1] + grid[m-1][i];
	}

	for (int i = m - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if(DP[i+1][j]>DP[i][j+1])
				DP[i][j] = DP[i][j+1] + grid[i][j];
			else
				DP[i][j] = DP[i+1][j] + grid[i][j];
		}
	}
	return DP[0][0];
}
