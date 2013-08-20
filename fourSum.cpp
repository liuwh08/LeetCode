#include "fourSum.h"
#include <algorithm>

using namespace std;

vector<vector<int> > Solution::fourSum(vector<int> & num, int target) {
	vector<vector<int> > res;
	int len = num.size();
	sort(num.begin(), num.end());
	for (int i = 0; i < len - 3; ++i)
	{
		for (int j = i + 1; j < len - 2; ++j)
		{
			int start = j + 1, end = len - 1;
			while(start<end){
				int sum = num.at(i) + num.at(j) +num.at(start) + num.at(end);
				if( sum == target) {
					vector<int> tmp;
					tmp.push_back(num.at(i));
					tmp.push_back(num.at(j));
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
				else if(sum>target)
					end--;
				else start++;
			}
			while((j<len - 2)&&(num.at(j) == num.at(j+1)))
				j++;
		}
		while((i<len - 3)&&(num.at(i) == num.at(i+1)))
			i++;
	}
	return res;
}
