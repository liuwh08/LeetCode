#include "minWindow.h"
#include <unordered_map>
#include <climits>

using namespace std;

string Solution::minWindow(string S, string T) {
  	unordered_map<char, int> stat_T;
	unordered_map<char, int> stat_S;
	for(int i = 0; i < T.length(); i++) {
	  	stat_T[T[i]]++;
	}
	int start = 0, end = 0;
	int min_start = 0, min_end = 0, minL = INT_MAX;
	int appeared = 0;
	while(end<S.length()) {
	  	if(stat_T.find(S[end]) != stat_T.end() ) {
		  	stat_S[S[end]]++;
			if(stat_S[S[end]] <= stat_T[S[end]])
			  	appeared++;
		}
		if(appeared == T.length() ){
		  	while(stat_T.find(S[start]) == stat_T.end() || stat_S[S[start]]> stat_T[S[start]]) {
			  	stat_S[S[start]]--;
				start++;
			}
			if((end - start) < minL) {
			  	minL = end -start + 1;
				min_start = start;
				min_end = end;
			}
		}
		end++;
	}
	if(minL == INT_MAX)
	  	return "";
	return S.substr(min_start, minL);
}
