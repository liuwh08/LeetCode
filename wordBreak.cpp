#include "wordBreak.h"

using namespace std;

bool isWordBreak(string s, unordered_set<string>& words, unordered_set<string>& unmatch) {
  	if( s == "")
	  	return true;
	for(int i = 1; i<= s.length(); i++) {
	  	string prefix = s.substr(0, i);
		auto f_res = words.find(prefix);
		if( f_res != words.end()) {
		  	string suffix = s.substr(i);
			if(unmatch.find(suffix) != unmatch.end()) continue;
			bool isSuffixWordBreak = isWordBreak(suffix, words, unmatch);
			if(isSuffixWordBreak) 
			  	return true;
			else{
			  	unmatch.insert(suffix);
			}
		}
	}
	return false;
}

bool Solution::wordBreak(string s, unordered_set<string> & words) {
  	unordered_set<string> unmatch;
	return isWordBreak(s, words, unmatch);
}
