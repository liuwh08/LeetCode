#include "generateParenthesis.h"

using namespace std;

void generateParString(int numleftPar, int numrightPar, string& current, vector<string>& res, const int n) {
       if(numleftPar + numrightPar == 2*n) {
		res.push_back(current);
		return;
       }
       if(numleftPar<n) {
		current.push_back('(');
		generateParString(numleftPar + 1, numrightPar, current, res, n);
		current.resize(current.size() - 1);
       }
       if(numrightPar<numleftPar) {
	       current.push_back(')');
	       generateParString(numleftPar, numrightPar + 1, current, res, n);
	       current.resize(current.size() - 1);
       }
       return;
}

vector<string> Solution::generateParenthesis(int n) {
	string current;
	vector<string> res;
	generateParString(0, 0, current, res, n);
	return res;
}
     
