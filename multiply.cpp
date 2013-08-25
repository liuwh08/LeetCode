#include "multiply.h"

using namespace std;

string Solution::multiply(string num1, string num2) {
	if(num1.length()==0 || num2.length() == 0)
		return "0";
	if(num1 == "0" || num2 == "0")
		return "0";
	string res(num1.length() + num2.length() + 1, '0');
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < num1.length(); ++i)
	{
		int digit1 = num1[i] - '0';
		int carry = 0;
		for (int j = 0; j < num2.length() ; j++)
		{
			int digit2 = num2[j] - '0';
			int remain = res[i+j] - '0';
			res[i+j] = (digit1 * digit2 + remain + carry) % 10 + '0';
			carry = (digit1 * digit2 + remain + carry)/10;
		}
		if(carry>0) {
			int remain = res[i + num2.length()] - '0';
			res[i + num2.length()] = (carry + remain) % 10 + '0';
		}
	}

	reverse(res.begin(), res.end());
	int start = 0;
	while(start < res.length() && res.at(start) == '0')
		start ++;
	return res.substr(start, res.size() - start);
}

