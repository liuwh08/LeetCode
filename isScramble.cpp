#include "isScramble.h"
#include <unordered_map>

using namespace std;

bool Solution::isScramble(string s1, string s2) {
  	if(s1 == s2)
	  	return true;
  	if( s1.size() != s2.size() )
	  	return false;
	unordered_map<char, int> count;
	for(auto i = s1.begin(); i != s1.end(); i++) {
	  	count[*i]++;
	}
	for(auto i = s2.begin(); i != s2.end(); i++) {
	  	if(count.find(*i) != count.end()) {
		  	count[*i]--;
		} else 
		  	return false;
	}
	for(auto i = count.begin(); i!= count.end(); i++) {
	  	if(i->second != 0) {
		  	return false;
		}
	}
	for(auto i = 1; i < s1.length(); ++i) {
	  	bool res = isScramble( s1.substr(0, i), s2.substr(0,i) ) && isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
		res = res || (isScramble( s1.substr(0, i) , s2.substr(s2.size() - i, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)));
		if(res) return true;
	}
	return false;
	
}

