#include "subsets.h"
#include <algorithm>

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

vector<vector<int> > Solution::subsets(vector<int> & S) {
  	vector<vector<int> > res;
	res.push_back(vector<int>());
	sort(S.begin(), S.end());
	for (int i = 1; i <= S.size(); ++i){
	  	vector<int> current;
	  	generateCombinations(S, current, res, 0, i, 0);
	}
	return res;
}
