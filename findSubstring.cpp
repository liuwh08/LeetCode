#include "findSubstring.h"
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> Solution::findSubstring(string S, vector<string> &L) {
	vector<int> res;
	map<string, int> expected_count;
	map<string, int> current_count;
	for (int i = 0; i < L.size(); ++i)
	{
		expected_count[L[i]]++;
	}
	if(L.size()==0)
		return res;
	int n = L.size()*L[0].length(), m = L.size(), l = L[0].length(), slen = S.length();
	cout<<n<<' '<<m<<' '<<l<<' '<<S.length()<<endl;
	int start = 0;
	while(start<=(slen - n)) {
		cout<<"In the Loop"<<endl;
		cout<<"Now start and S.length()-n :"<<start<<' '<<slen - n<<endl;
		string sub = S.substr(start,n);
		bool isSubstring = true;
		current_count.clear();
		for (int i = 0; i < m; ++i)
		{
			string subsub = sub.substr(i*l, l);
			if(expected_count.find(subsub) != expected_count.end()){
				current_count[subsub]++;
			}else {
				isSubstring = false;
				break;
			}

			if(current_count[subsub]>expected_count[subsub]){
				isSubstring = false;
				break;
			}
		}
		if(isSubstring)
			res.push_back(start);
		start++;
	}
	return res;
}

