#include "combinationSum2.h"
#include <algorithm>
#include <set>

using namespace std;

void generateCombinations(vector<vector<int> >& res, vector<int>& sol, vector<bool>& isUsed, int start, int sum,const int target,const vector<int>& candidates)  {
	if(sum>target)
		return;
	if(sum == target){
		res.push_back(sol);
		return;
	}
	for (int i = start; i < candidates.size(); ++i)
	{
		if(!isUsed[i]){
		sol.push_back(candidates.at(i));
		isUsed[i] = true;
		generateCombinations(res, sol, isUsed, i + 1, sum + candidates.at(i), target, candidates);
		sol.pop_back();
		isUsed[i] = false;
		while(i<candidates.size() - 1 && candidates[i] == candidates[i+1]) i++;
		}
	}
	return;
}

vector<vector<int> > Solution::combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int> > res;
	vector<int> sol;
	vector<bool> isUsed(candidates.size(), false);
	sort(candidates.begin(), candidates.end());
	generateCombinations(res, sol, isUsed, 0, 0, target, candidates);
	return res;
}

