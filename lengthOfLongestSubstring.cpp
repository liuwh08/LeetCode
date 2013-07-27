#include "lengthOfLongestSubstring.h"
#include <iostream>

using namespace std;

int Solution::lengthOfLongestSubstring(string s) {
	string sub;
	if(s.empty())
		return 0;
	int max_l = 1;
	int start = 0, l = 1;
	while((start+l)<s.length()) {
		sub = s.substr(start, l);
		char ch = s.at(start + l);
		size_t found = sub.find(ch);
		cout<<"char and substr: "<<ch<<' '<<sub<<endl;
		if(found == s.npos)
			l++;
		else{
			start += found + 1;
			l -= found;
		}
		if(l>max_l)
			max_l = l;

	}
	return max_l;
	
}
