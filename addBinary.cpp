#include "addBinary.h"
#include <algorithm>

using namespace std;

string Solution::addBinary(string a, string b) {
	string res;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int m = a.size(), n = b.size();
	int i = 0, carry = 0;
	while((i<m)||(i<n)){
		int digit1;
		int digit2;
		if(i>=m)
			digit1 = 0;
		else 
			digit1 = a[i] - '0';
		if(i>=n)
			digit2 = 0;
		else
			digit2 = b[i] - '0';
		int sum = digit1 + digit2 + carry;
		res.push_back('0' + (sum%2));
		carry = sum/2;
		i++;
	}
	if(carry == 1)
		res.push_back('1');
	reverse(res.begin(), res.end());
	return res;
}
