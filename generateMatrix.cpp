#include "generateMatrix.h"

using namespace std;

vector<vector<int> > Solution::generateMatrix(int n) {
	vector<vector<int> > res(n, vector<int>(n, 0));
	if(n==0)
		return res;
	int m = n;
	vector<vector<bool> > isVisited(n, vector<bool>(m, false));
	int current = 1;
	int i = 0, j = 0;
	int llimit = 0, rlimit = m - 1, uplimit = 0, downlimit = n - 1;
	int dj[] = {1, 0, -1, 0};
	int di[] = {0, 1, 0, -1};
	int direction = 0;
	while((i>=uplimit)&&(i<=downlimit)&&(j>=llimit)&&(j<=rlimit)&&(!isVisited[i][j])) {
		res[i][j] = current;
		isVisited[i][j] = true;
		current++;
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

