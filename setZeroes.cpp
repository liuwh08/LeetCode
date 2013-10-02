#include "setZeroes.h"

using namespace std;

void Solution::setZeroes(vector<vector<int> >& matrix) {
  	bool zeroFirstRow = false;
	bool zeroFirstCol = false;
	int n = matrix.size();
	if(n == 0)
	  	return;
	int m = matrix[0].size();
	for (int i = 0; i < n; ++i)
	{
	  	if(matrix[i][0] == 0){
		  	zeroFirstCol = true;
			break;
		}
	}
	for (int i = 0; i < m; ++i)
	{
	  	if(matrix[0][i] == 0){
		  	zeroFirstRow = true;
			break;
		}
	}
	for (int i = 1; i < n; ++i)
	{
	  	for (int j = 1; j < m; ++j)
	  	{
	  	  	if(matrix[i][j] == 0){
			  	matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
	  	}
	}
	for (int i = 1; i < n; ++i)
	{
	  	if(matrix[i][0] == 0){
		  	for (int j = 0; j < m; ++j)
		  	{
		  	  	matrix[i][j] = 0;
		  	}
		}
	}
	for (int i = 1; i < m; ++i)
	{
	  	if(matrix[0][i] == 0){
		  	for (int j = 0; j < n; ++j)
		  	{
		  	  	matrix[j][i] = 0;
		  	}
		}
	}
	if(zeroFirstCol)
		for (int i = 0; i < n; ++i){
	  		matrix[i][0] = 0;
		}
	if(zeroFirstRow)
		for (int i = 0; i < m; ++i){
	  		matrix[0][i] = 0;
		}

	return;

}
