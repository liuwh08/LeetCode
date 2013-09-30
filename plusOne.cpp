#include "plusOne.h"
#include <algorithm>

using namespace std;

vector<int> Solution::plusOne(vector<int>& digits) {
	vector<int> res = digits;
	reverse(res.begin(), res.end());
	bool carry = 1;
   	int i = 0;
   	while(carry && i<res.size()) {
		int current = res[i];	
		current++;
		carry = false;
		if(current>=10) {
			res[i] = current%10;
			carry = true;
		}
		else {
		  	res[i] = current;
		}
		i++;
   	}
	if(carry)
		res.push_back(1);
	reverse(res.begin(), res.end());
	return res;
}
