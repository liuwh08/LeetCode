#include "largestRectangleArea.h"

using namespace std;

int Solution::largestRectangleArea(vector<int> &height) {
	int index = 0;
	int maxA = 0;
	while(index<height.size() ){
	  	int current = index;
		while(current < height.size() && height[index]<=height[current]) {
		  	current++;
		}
		int right_bound = current;
		current = index;
		while(current>=0 && height[index] <= height[current])
		  	current--;
		int left_bound = current;
		int area = height[index] * (right_bound - left_bound + 1);
		if(area > maxA)
		  	maxA = area;
		index++;
	}
	return maxA;
}
