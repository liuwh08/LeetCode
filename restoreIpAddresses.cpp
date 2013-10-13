#include "restoreIpAddresses.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

void generateIpAddresses(vector<string>& res, vector<string>& current, int step, string s) {
  	if(step == 4 && s == "") {
	  	string cat_all;
		for(auto str : current) {
		  	cat_all = cat_all + str + ".";
		}
		cat_all = cat_all.substr(0, cat_all.length() - 1);
		res.push_back(cat_all);
	} else {
	  	int min_length = s.length() > 3 ? 3 : s.length();
		for (int i = 1; i <= min_length; ++i){
		  	string head = s.substr(0, i);
			if(atoi(head.c_str()) > 255 || (head[0] == '0' && head.length() > 1 ) )
			  	continue;
			current.push_back(head);
			generateIpAddresses(res, current, step + 1, s.substr(i, s.length() - i) );
			current.pop_back();
		}
	}
}

vector<string> Solution::restoreIpAddresses(string s) {
  	vector<string> res;
	if(s.length() > 12)
	  	return res;
	vector<string> current;
	generateIpAddresses(res, current, 0, s);
	return res;
}
