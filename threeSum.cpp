#include "threeSum.h"
#include <algorithm>

using namespace std;

vector<vector<int> > Solution::threeSum(vector<int> & num) {
	sort(num.begin(), num.end());
	int len = num.size();
	vector<vector<int> > res;
	for (int i = 0; i < len; ++i)
	{
		int target = - num.at(i);
		int start = i + 1, end = len - 1;
		while(start<end) {
			if (num.at(start) + num.at(end) == target)
			{
				vector<int> tmp;
				tmp.push_back(num.at(i));
				tmp.push_back(num.at(start));
				tmp.push_back(num.at(end));
				res.push_back(tmp);
				start++;
				end--;
				while((start<end)&&(num.at(start) == num.at(start - 1)))
					start++;
				while((start<end)&&(num.at(end) == num.at(end + 1)))
				       end--;	
			}
			else
			{
				if(num.at(start) + num.at(end) > target)
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


