#include "recoverTree.h"
#include <vector>
#include <algorithm>

using namespace std;

void inorderTraverse(vector<TreeNode*>& res, vector<int>& res_int, TreeNode* current) {
  	if(current == nullptr)
	 	return;
	inorderTraverse(res, res_int, current->left);
	res.push_back(current);
	res_int.push_back(current->val);
	inorderTraverse(res, res_int, current->right);
}

void Solution::recoverTree(TreeNode* root) {
  	vector<TreeNode*> inorder;
	vector<int> inorder_int;
	inorderTraverse(inorder, inorder_int, root);
	sort(inorder_int.begin(), inorder_int.end());
	for (int i = 0; i < inorder.size() ; ++i){
	  	inorder[i]->val = inorder_int[i];
	}
}
