#include "threeSumClosest.h"
#include <algorithm>
#include <limits>
#include <cstdlib>

using namespace std;

int Solution::threeSumClosest(vector<int> & num, int target) {
	sort(num.begin(), num.end());
	int len = num.size();
	int minimum = INT_MAX, res;
	for (int i = 0; i < len; ++i)
	{
		int start = i + 1, end = len - 1;
		while(start<end) {
			if (num.at(start) + num.at(end) + num.at(i) == target)
			{
				minimum = 0;
				res = target;
				break;
				start++;
				end--;
				while((start<end)&&(num.at(start) == num.at(start - 1)))
					start++;
				while((start<end)&&(num.at(end) == num.at(end + 1)))
				       end--;	
			}
			else
			{
				int sum = num.at(start) + num.at(end) + num.at(i);
				if(abs(sum - target)<minimum){
					minimum = abs(sum - target);
					res = sum;
				}
				if(sum > target)
					end--;
				else
					start ++;
			}
		}
		while((i<len - 1)&&(num.at(i) == num.at(i+1)))
			i++;

	}
	return res;
}


