#include "solveSudoku.h"
#include <iostream>

struct coordinates {
	int x;
	int y;
	coordinates(int a, int b): x(a), y(b) {}
};

using namespace std;

void printout(const vector<vector<char> >& board) {
	for (int i = 0; i < board.size() ; ++i)
	{
		for (int j = 0; j < board[i].size() ; ++j)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isValid(vector<vector<char> > & board, const coordinates& p) {
	int row = p.x;
	int colum = p.y;
	char val = board[row][colum];
	//cout<<"Current in isValid, "<<row<<' '<<colum<<' '<<val<<endl;
	if(val<'1'||val>'9') 
		return false;
	for (int i = 0; i < board.at(row).size(); ++i)
	{
		if((i != colum)&&(board.at(row).at(i) !='.')&&(board[row][i] == val))
			return false;
	}
	//cout<<"Pass row test!!!"<<endl;
	for (int i = 0; i < board.size(); ++i)
	{
		if((i != row)&&(board.at(i).at(colum) != '.')&&(board[i][colum] == val))
			return false;
	}
	//cout<<"Pass colum test!!!"<<endl;
	const int row_sec_start = (row/3) * 3 ;
	const int colum_sec_start = (colum/3) * 3 ;
	for (int i = row_sec_start; i < row_sec_start+3; ++i)
	{
		for (int j = colum_sec_start; j < colum_sec_start+3; ++j)
		{
			if((i != row) && (j!= colum) &&(board.at(i).at(j) != '.')&&(board[i][j] == val))
				return false;
		}
		
	}
	return true;
}

void Solution::solveSudoku(vector<vector<char> > & board) {
	vector<coordinates> holes;
	holes.clear();
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size() ; ++j)
		{
			if(board[i][j] == '.'){
				holes.push_back(coordinates(i,j));
			}
		}
	}

	if(holes.size()==0)
		return;

	int current = 0;
	coordinates& Coor = holes[current];
	board[Coor.x][Coor.y] = '1';
	bool forward = true;
	while(current>=0) {
		if(current>=holes.size())
			return;
		Coor = holes[current];
		cout<<"Current = "<<current<<"  COOR: "<<Coor.x<<' '<<Coor.y<<endl;
		//printout(board);
		if(forward) {
			bool valid = isValid(board, Coor);
			if(valid) {
				current++;
			}else
				forward = false;
		}else {
			char& ch = board[Coor.x][Coor.y];
			if(ch >= '9') {
				ch = '.';
				current--;
			} else {
				ch += 1;
				forward = true;
			}
		}
	}

	return;
}
