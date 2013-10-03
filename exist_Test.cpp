#include "exist.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  	Solution s;
	vector<vector<char> > board;
	string word = "AAB";
	vector<char> tmp;
	tmp.push_back('C');
	tmp.push_back('A');
	tmp.push_back('A');
	board.push_back(tmp);
	tmp.clear();
	tmp.push_back('A');
	tmp.push_back('A');
	tmp.push_back('A');
	board.push_back(tmp);
	tmp.clear();
	tmp.push_back('B');
	tmp.push_back('C');
	tmp.push_back('D');
	board.push_back(tmp);
	tmp.clear();
	cout<< s.exist(board, word)<<endl;
  return 0;
}
