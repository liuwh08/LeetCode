#include "numDecodings.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int Solution::numDecodings(string s) {
  	if(s == "" || s=="0")
	  	return 0;
	if(s.length() == 1)
	    return 1;
	vector<int> dp(s.length(), 0);
	cout<<"Length = "<< s.length() <<endl;
	cout<<s[0]<<endl;
	if(s[0] != '0') dp[0] = 1;
	cout<<"Enter\n";
	if(s[1] != '0') dp[1] += dp[0];
	if( s[0] == '1' || (s[0] == '2' && s[1] <='6')) dp[1] += 1;
	for(int i = 2; i<s.length(); ++i) {
	  	if(s[i] != '0')
		  	dp[i] += dp[i-1];
		if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <='6'))
		  	dp[i] += dp[i-2];
	}
	return dp[s.length()-1];
}
