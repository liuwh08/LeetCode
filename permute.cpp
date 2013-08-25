#include "permute.h"

using namespace std;

void generatePermutations(vector<vector<int> > & res, vector<int>& nums, vector<int> sol, vector<bool> isUsed, int depth) {
	if(depth == nums.size()) {
		res.push_back(sol);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if(!isUsed[i]) {
			sol.push_back(nums[i]);
			isUsed[i] = true;
			generatePermutations(res,nums,sol,isUsed, depth + 1);
			isUsed[i] = false;
			sol.pop_back();
		}
	}
	return;
}

vector<vector<int> > Solution::permute(vector<int> &nums) {
	vector<vector<int> > res;
	vector<int> sol;
	vector<bool> isUsed(nums.size(), false);
	generatePermutations(res, nums, sol, isUsed, 0);
	return res;
}
