#include "sortedArrayToBST.h"

using namespace std;

TreeNode* sortedToBST(vector<int>& nums, int start, int end) {
  	if(start>end) {
	  	return nullptr;
	}
	int mid = (start + end)/2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = sortedToBST(nums, start, mid - 1);
	root->right = sortedToBST(nums, mid + 1, end);
	return root;
}

TreeNode* Solution::sortedArrayToBST(vector<int> & nums) {
  	return sortedToBST(nums, 0, nums.size() - 1);
}
