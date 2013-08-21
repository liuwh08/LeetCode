#include "longestValidParentheses.h"
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int Solution::longestValidParentheses(string s) {
	const char * str = s.c_str();
	stack<const char *> st;
	const char *p = str;
	int max_length = 0;
	while(*p != '\0') {
		if(*p == '(') 
			st.push(p);
		else if((!st.empty())&&(*(st.top())=='(')){
			st.pop();
			max_length = max(max_length, p - (st.empty()? str - 1: st.top()));
		} else 
			st.push(p);
		p++;
	}
	return max_length;
}
	
