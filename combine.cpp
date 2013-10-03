#include "combine.h"

using namespace std;

void generateCombinations(vector<int>& nums, vector<int> & current, vector<vector<int> > & res, int depth, const int k, int start) {
  	if(depth == k) {
	  	res.push_back(current);
	} else {
	  	for(int i = start; i < nums.size(); i++) {
	  		current.push_back(nums[i]);
			generateCombinations(nums, current, res, depth + 1, k, i + 1);
			current.pop_back();
		}
	}
}

vector<vector<int> > Solution::combine(int n, int k) {
  	vector<int> nums;
	for (int i = 1; i < n+1; ++i){
	  	nums.push_back(i);
	}
	vector<vector<int> > res;
	vector<int> current;
	generateCombinations(nums, current, res, 0, k, 0);
	return res;
}
