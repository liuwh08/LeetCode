#include "spiralOrder.h"

using namespace std;

vector<int> Solution::spiralOrder(vector<vector<int> > &matrix) {
	int n = matrix.size();
	vector<int> res;
	if(n==0)
		return res;
	if(n==1)
		return matrix[0];
	int m = matrix[0].size();
	vector<vector<bool> > isVisited(n, vector<bool>(m, false));
	int i = 0, j = 0;
	int llimit = 0, rlimit = m - 1, uplimit = 0, downlimit = n - 1;
	int dj[] = {1, 0, -1, 0};
	int di[] = {0, 1, 0, -1};
	int direction = 0;
	while((i>=uplimit)&&(i<=downlimit)&&(j>=llimit)&&(j<=rlimit)&&(!isVisited[i][j])) {
		res.push_back(matrix[i][j]);
		isVisited[i][j] = true;
		i += di[direction];
		j += dj[direction];
		if(j>rlimit) {
			j = rlimit;
			i++;
			direction = 1;
			uplimit++;
			continue;
		}
		if(j<llimit) {
			j = llimit;
			i--;
			direction = 3;
			downlimit--;
			continue;
		}
		if(i<uplimit) {
			i = uplimit;
			j++;
			direction = 0;
			llimit++;
			continue;
		}
		if(i>downlimit) {
			i = downlimit;
			j--;
			direction = 2;
			rlimit--;
		}
	}
	return res;
}

