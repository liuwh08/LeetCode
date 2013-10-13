#include "isInterleave.h"
#include "vector"

using namespace std;

bool Solution::isInterleave(string s1, string s2, string s3) {
	if((s1.size() + s2.size() != s3.size()))
	  	return false;
	if( s1.size() == 0)
	  	return s2 == s3;
	if( s2.size() == 0)
	  	return s1 == s3;
  	vector<vector<bool> > dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
	dp[0][0] = true;
	for(int i = 1; i <= s2.length(); ++i) {
	  	dp[0][i] = dp[0][i-1] && s2[i - 1] == s3[i - 1];
	}
	for(int i = 1; i <= s1.length(); ++i) {
	  	dp[i][0] = dp[i-1][0] && s1[i - 1] == s3[i - 1];
	}

	for(int i = 1; i<= s1.length(); ++i) 
	  	for(int j = 1; j<=s2.length(); ++j) {
		  	dp[i][j] = ( s3[i+j-1] == s1[i-1] && dp[i-1][j] ) || (s3[i + j - 1] == s2[j-1] && dp[i][j-1]);
		}
	return dp[s1.length()][s2.length()];
}
