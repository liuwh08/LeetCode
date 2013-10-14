#include "hasPathSum.h"
#include <vector>

using namespace std;

bool pathSum(TreeNode* root, int current_sum, const int target) {
  	if(!root) 
	  	return false;
	current_sum += root->val;
	if( !root->left && !root->right) {
	  	return current_sum == target;
	}
	return pathSum(root->left, current_sum, target) || pathSum(root->right, current_sum, target);
}

bool Solution::hasPathSum(TreeNode* root, int sum) {
  	return pathSum(root, 0, sum);
}
