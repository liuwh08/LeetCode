#include "combinationSum.h"
#include <algorithm>

using namespace std;

void generateCombinations(vector<vector<int> >& res, vector<int>& sol, int start, int sum,const int target,const vector<int>& candidates)  {
	if(sum>target)
		return;
	if(sum == target){
		res.push_back(sol);
		return;
	}
	for (int i = start; i < candidates.size(); ++i)
	{
		if((i>0)&&(candidates.at(i) == candidates.at(i-1)))
			continue;
		sol.push_back(candidates.at(i));
		generateCombinations(res, sol, i, sum + candidates.at(i), target, candidates);
		sol.pop_back();
	}
	return;
}

vector<vector<int> > Solution::combinationSum(vector<int>& candidates, int target) {
	vector<vector<int> > res;
	vector<int> sol;
	sort(candidates.begin(), candidates.end());
	generateCombinations(res, sol, 0, 0, target, candidates);
	return res;
}

