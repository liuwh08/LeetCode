#include "minDistance.h"
#include <vector>

using namespace std;

int Solution::minDistance(string word1, string word2) {
  	if(word1 == "")
	  	return word2.length();
	if(word2 == "")
	  	return word1.length();
  	vector<vector<int> > dp(word1.size() + 1, vector<int>(word2.size() + 1, 0) );

	for (int i = 0; i < word1.length() ; ++i){
	  	dp[i][0] = i;
	}

	for (int j = 0; j < word2.length() ; ++j){
	  	dp[0][j] = j;
	}

	for (int i = 1; i <= word1.length() ; ++i){
	  	for (int j = 1; j <= word2.length() ; ++j){
		  	if(word1[i-1]==word2[j-1]) {
			  	dp[i][j] = dp[i-1][j-1];
				continue;
			}
			int min = dp[i-1][j-1];
			if(dp[i][j-1]<min)
			  	min = dp[i][j-1];
			if(dp[i-1][j]<min)
			  	min = dp[i-1][j];
			dp[i][j] = min + 1;
	  	}
	}
	return dp[word1.length()][word2.length()];
}
