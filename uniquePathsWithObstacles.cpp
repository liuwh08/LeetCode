#include "uniquePathsWithObstacles.h"

using namespace std;

int Solution::uniquePathsWithObstacles(vector<vector<int> > & obstacleGrid) {
	vector<vector<int> > DP(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	if(obstacleGrid[m-1][n-1] == 0)
		DP[m-1][n-1] = 1;
	for (int i = m - 2; i >= 0; i--)
	{
		if(obstacleGrid[i][n-1] == 0)
			DP[i][n-1] = DP[i+1][n-1];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if(obstacleGrid[m-1][i] == 0)
			DP[m-1][i] = DP[m-1][i+1];
	}

	for (int i = m - 2; i >=0 ; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if(obstacleGrid[i][j] == 1)
				DP[i][j] = 0;
			else
				DP[i][j] = DP[i+1][j] + DP[i][j+1];
		}
	}
	return DP[0][0];
}

