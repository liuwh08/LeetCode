#include "numTrees.h"

int Solution::numTrees(int n) {
  	if(n==0 || n==1)
	  	return 1;
  	int *dp = new int[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; ++i) {
	  	dp[i] = 0;
	  	for(int k = 0; k<= i - 1; ++k) {
		  	dp[i] += dp[k] * dp[i-k-1];
		}
	}
	return dp[n];
}
