#include "isValidBST.h"

bool validBST(TreeNode* root, int min, int max){
  	if(!root) {
	  	return true;
	}
	return (root->val > min && root->val < max && validBST(root->left, min, root->val) && validBST(root->right, root->val, max));
}


bool Solution::isValidBST(TreeNode *root) {
  	return validBST(root, INT_MIN, INT_MAX);
}
