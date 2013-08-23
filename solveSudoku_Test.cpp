#include "solveSudoku.h"

#include <iostream>
#include <string>

using namespace std;

void pushchar(string& str, vector<vector<char> > & board) {
	vector<char> tmp;
	for (int i = 0; i < str.length(); ++i)
	{
		tmp.push_back(str[i]);
	}
	board.push_back(tmp);
}

int main(int argc, char *argv[])
{
	Solution S;
	vector<vector<char> > board;
	string s = "..9748...";
	pushchar(s, board);
	s = "7........";
	pushchar(s, board);
	s = ".2.1.9...";
	pushchar(s, board);
	s = "..7...24.";
	pushchar(s, board);
	s = ".64.1.59.";
	pushchar(s, board);
	s = ".98...3..";
	pushchar(s, board);
	s = "...8.3.2.";
	pushchar(s, board);
	s = "........6";
	pushchar(s, board);
	s = "...2759..";
	pushchar(s, board);
	S.solveSudoku(board);
	return 0;
}

