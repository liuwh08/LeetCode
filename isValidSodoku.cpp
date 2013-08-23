#include "isValidSodoku.h"
#include <set>

using namespace std;

bool Solution::isValidSodoku(vector<vector<char> > &board) {
	set<char> nums;
	nums.clear();
	for (int i = 0; i < board.size(); ++i)
	{
		nums.clear();
		for (int j = 0; j < board[i].size() ; ++j)
		{
			if(board[i][j] == '.')
				continue;
			if(nums.find(board[i][j]) != nums.end())
				return false;
			else
				nums.insert(board[i][j]);
		}
	}
	for (int i = 0; i < board[0].size() ; ++i)
	{
		nums.clear();
		for (int j = 0; j < board.size() ; ++j)
		{
			if(board[j][i] == '.')
				continue;
			if(nums.find(board[j][i]) != nums.end())
				return false;
			else
				nums.insert(board[j][i]);
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			nums.clear();
			for (int k = 0; k < 3; ++k)
			{
				for (int l = 0; l < 3; ++l)
				{
					char ch = board[3*i + k][3*j + l];
					if(ch == '.')
						continue;
					if(nums.find(ch) != nums.end())
						return false;
					else
						nums.insert(ch);
				}
			}
		}
	}
	return true;
}
