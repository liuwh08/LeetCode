#include "isBalanced.h"
#include <vector>

using namespace std;

TreeNode* getHeightTree(TreeNode* root) {
  	if(!root) 
	  	return new TreeNode(0);
	TreeNode* leftTree = getHeightTree(root->left);
	TreeNode* rightTree = getHeightTree(root->right);
	int height = max(leftTree->val, rightTree->val) + 1;
	TreeNode* R = new TreeNode(height);
	R->left = leftTree;
	R->right = rightTree;
	return R;
}

bool balanced(TreeNode* heightTree) {
  	if(heightTree->val == 1 || heightTree->val == 0)
	  	return true;
	return abs(heightTree->left->val - heightTree->right->val) <=1 && balanced(heightTree->left) && balanced(heightTree->right);
}

bool Solution::isBalanced(TreeNode* root) {
  	TreeNode* heightTree = getHeightTree(root);
	return balanced(heightTree);
}
