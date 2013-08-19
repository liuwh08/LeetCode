#include "maxArea.h"
#include <algorithm>

using namespace std;

int Solution::maxArea(vector<int>& height) {
	int i = 0, j = height.size() - 1;
	int max = min(height.at(i), height.at(j))*(j - i);
	while(j>i) {
		if (height.at(i)>height.at(j))
		{
			j--;
		}
		else
		{
			i++;
		}
		int tmp = min(height.at(i), height.at(j))*(j - i);
		if (tmp > max )
			max = tmp;
	}
	return max;
}
