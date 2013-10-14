#include "pathSum.h"

using namespace std;


void generatePath(TreeNode* root, int current_sum, vector<int> & current_nums, vector<vector<int> > & res, const int target) {
  	if(!root) 
	  	return;
	current_sum += root->val;
	current_nums.push_back(root->val);
	if( !root->left && !root->right && current_sum == target) {
	  	res.push_back(current_nums);
		return;
	}
	if(root->left) {
	  	generatePath(root->left, current_sum, current_nums, res, target);
		current_nums.pop_back();
	}
	if(root->right) {
	  	generatePath(root->right, current_sum, current_nums, res, target);
		current_nums.pop_back();
	}

}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
  	vector<vector<int> > res;
	vector<int> nums;
	generatePath(root, 0, nums, res, sum);
	return res;
}
