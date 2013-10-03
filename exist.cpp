#include "exist.h"
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dfs(int currentx, int currenty, vector<vector<bool> > & visited, vector<vector<char> > & board, int depth, const string & word) {
  	cout<<"Current Position Is: "<< currenty << "      " << currentx<<endl;
  	if(depth == word.length() - 1 )
	  	return true;
	for (int i = 0; i < 4; ++i)
	{
	  	int nx = currentx + dx[i];
		int ny = currenty + dy[i];
		if( nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size())
		  	continue;
		if( visited[ny][nx])
		  	continue;
		if( board[ny][nx] != word[depth + 1] )
		  	continue;
		visited[ny][nx] = true;
		if(dfs(nx, ny, visited, board, depth + 1, word) )
			return true;
		visited[ny][nx] = false;
	}
	return false;
}

bool Solution::exist(vector<vector<char> > & board, string word) {
  	if(word == "") 
	  	return true;
	for (int i = 0; i < board.size() ; ++i){
	  	for (int j = 0; j < board[0].size() ; ++j){
		  	if(board[i][j] == word[0]) {
			  	cout<<endl;
				vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
				visited[i][j] = true;
			  	if(dfs(j, i, visited, board, 0, word))
				  	return true;
			}
	  	}
	}
	return false;
}
