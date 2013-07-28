#include "longestPalindrome.h"
#include <cstring>

using namespace std;

string Solution::longestPalindrome(string s) {
	int len = s.length();
	int P[1000][1000];
	memset(P, 0, len*len*sizeof(int));
	int maxlen = 0, start = 0, end = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			P[j][i] = (s[j] == s[i])&&((i - j == 1) || P[j+1][i-1]);
			if (P[j][i]&&(maxlen<i-j+1))
			{
				maxlen = i-j+1;
				start = j;
				end = i;	
			}
		}
		P[i][i] = 1;
	}
	return s.substr(start, end - start + 1);	
}


