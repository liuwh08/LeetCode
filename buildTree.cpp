#include "buildTree.h"
#include <algorithm>

using namespace std;

TreeNode* build(int prestart, int preend, int instart, int inend, vector<int>& preorder, vector<int>& inorder) {
  	if(prestart > preend) 
	  	return nullptr;
	TreeNode *root = new TreeNode(preorder[prestart]);
	auto it = find(inorder.begin() + instart, inorder.begin() + inend + 1, preorder[prestart]);
	int left_length = it - inorder.begin() - instart;
	int right_length = inend - (it - inorder.begin());
	root->left = build(prestart + 1, prestart + left_length, instart, it - inorder.begin() - 1, preorder, inorder);
	root->right = build( prestart + left_length + 1, preend, it - inorder.begin() + 1, inend, preorder, inorder);
	return root;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
  	return build(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
}
