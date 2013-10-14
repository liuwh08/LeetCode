#include "numDistinct.h"
#include <vector>

using namespace std;

int Solution::numDistinct(string S, string T) {
  	vector<vector<int> > dp(S.length() + 1, vector<int>(T.length() + 1));
	for(int i = 0; i <= S.length() ; ++i) {
	  	dp[i][0] = 1;
	}
	for(int i = 1; i<=S.length() ; ++i) 
	  	for(int j = 1; j<=T.length(); ++j){
		  	dp[i][j] = dp[i-1][j];
		  	if( S[i-1] == T[j-1]) 
			  	dp[i][j] += dp[i-1][j-1];
		}
	return dp[S.length()][T.length()];
}
