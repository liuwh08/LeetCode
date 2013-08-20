#include "isValid.h"
#include <stack>
#include <iostream>
using namespace std;

bool Solution::isValid(string s) {
	stack<char> st;
	int i = 0;
	while(i<s.length()){
		cout<<i<<endl;
		if((s.at(i) == '(')||(s.at(i) == '[')||(s.at(i) == '{')) {
			st.push(s.at(i));
			i++;
		}
		else {
			if(st.empty())
				return false;
			char top = st.top();
			i++;
			st.pop();
			if((s.at(i-1) == ')')&&(top == '('))
				continue;
			if((s.at(i-1) == ']')&&(top == '['))
				continue;
			if((s.at(i-1) == '}')&&(top == '{'))
				continue;
			return false;
		}
	}
	return st.empty();
}


