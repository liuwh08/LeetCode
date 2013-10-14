#include "wordBreak.h"
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> generateWordBreak( unordered_set<string>& words, unordered_map<string, vector<string> >& matched, string s) {
  	if(matched.find(s) != matched.end() )
	  	return matched.at(s);
  	vector<string> res;
  	if( s == "") {
		return res;
	}
	if( words.find(s) != words.end() )
	  	res.push_back(s);
	for(int i = 1; i<=s.length(); ++i) {
	  	string prefix = s.substr(0, i);
		auto find_prefix = words.find(prefix);
		if( find_prefix != words.end() ) {
		  	string suffix = s.substr(i);
			auto WordBreakList = generateWordBreak(words, matched, suffix);
			for(auto str : WordBreakList) {
			  	res.push_back(prefix + " " + str);
			}

		}
	}
	matched.insert(make_pair(s, res));
	return res;
}

vector<string> Solution::wordBreak(string s, unordered_set<string>& words) {
  	vector<string> res;
	vector<string> current_words;
	unordered_map<string, vector<string> > unmatch;
	res = generateWordBreak(words, unmatch, s);
	return res;
}
