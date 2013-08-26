#include "totalQueens.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_sol(const vector<string> & sol){
       for (int i = 0; i < sol.size(); ++i)
       {
	       cout<<sol[i]<<endl;
       }
       cout<<endl;
       return;
}
void NQueenSolver(vector<vector<string> > & res,
		vector<string>& sol,
		vector<bool>& columns,
		vector<bool>& diag,
		vector<bool>& r_diag,
		int depth, const int n) {
	if(depth==n) {
		res.push_back(sol);
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if((!columns[i])&&(!diag[depth + i]) && (!r_diag[depth - i + (n - 1)])) {
			string str(n, '.');
			str[i] = 'Q';
			sol.push_back(str);
			columns[i] = true;
			diag[depth + i] = true;
			r_diag[depth - i + (n - 1)] = true;
			NQueenSolver(res, sol, columns, diag, r_diag, depth + 1, n);
			sol.pop_back();
			columns[i] = false;
			diag[depth + i] = false;
			r_diag[depth - i + (n - 1)]= false;
		}
	}

}

int Solution::totalNQueens( int n) {
	vector<vector<string> > res;
	vector<string> sol;
	vector<bool> columns(n, false);
	vector<bool> diag(2*(n-1), false);
	vector<bool> r_diag(2*(n-1), false);
	NQueenSolver(res, sol, columns, diag, r_diag, 0, n);
	return res.size();
}
