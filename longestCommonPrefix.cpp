#include "longestCommonPrefix.h"

using namespace std;

string Solution::longestCommonPrefix(vector<string> & strs) {
	string res = "";
	int i = 0;
	if(strs.size() == 0)
		return res;
	while(1) {
		if(i==strs.at(0).length())
			break;
		char ch = strs.at(0).at(i);
		bool isCommon = true;
		for(vector<string>::iterator j = strs.begin(); j != strs.end(); j++){
			if((*j).length()<=i) {
				isCommon = false;
				break;
			}
			if(((*j).length()>i) && ((*j).at(i) != ch)) {
				isCommon = false;
				break;
			}
		}
		if(isCommon) {
			res.push_back(ch);
			i++;
		}else
			break;
	}
	return res;
}
