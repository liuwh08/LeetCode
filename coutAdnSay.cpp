#include "coutAdnSay.h"
#include <sstream>

using namespace std;

string Solution::countAndSay(int n) {
	string s = "1";
	string new_str;
	for (int i = 1; i < n; ++i)
	{
		new_str = "";
		int count = 1;
		char digit = s[0];
		for (int j = 1; j < s.length(); ++j)
		{
			if(digit == s[j])
				count++;
			else {
				stringstream ss;
				ss<<count;
				new_str.append(ss.str());
				new_str.push_back(digit);
				digit = s[j];
				count = 1;
			}

		}
		stringstream ss;
		ss<<count;
		new_str.append(ss.str());
		new_str.push_back(digit);
		s = new_str;
	}
	return s;
}
