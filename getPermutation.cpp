#include "getPermutation.h"
#include <iostream>

using namespace std;

string Solution::getPermutation(int n, int k) {
	int* nums = new int[n];
	int n_factorial = 1;
	for (int i = 0; i < n; ++i)
	{
		nums[i] = i + 1;
		n_factorial *= (i + 1);
	}
	string res;
	k--;
	n_factorial = n_factorial/n;
	for (int i = 0; i < n; ++i)
	{
		cout<<n_factorial<<endl;
		int quotient = k/ n_factorial;
		int remainder = k % n_factorial;
		res.push_back( nums[quotient] + '0');
		for (int j = quotient; j < n-i-1; ++j)
		{
			nums[j] = nums[j+1];
		}
		k = remainder;		
		if(i<n-1)
			n_factorial = n_factorial/(n - i - 1);
	}
	return res;
}
