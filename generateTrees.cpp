#include "generateTrees.h"

using namespace std;

vector<TreeNode*> generate(int start, int end) {
  	if(start > end) {
	  	return vector<TreeNode*>(1, nullptr);
	} else {
	  	vector<TreeNode*> res;
	  	for(auto i = start; i <= end; ++i ) {
		  	vector<TreeNode*> left = generate(start, i - 1);
			vector<TreeNode*> right = generate(i + 1, end);
			for(auto left_tree : left)
			  	for(auto right_tree : right) {
				  	TreeNode* root = new TreeNode(i);
					root->left = left_tree;
					root->right = right_tree;
					res.push_back(root);
				}
		}
		return res;
	}
}

vector<TreeNode*> Solution::generateTrees(int n) {
  	return generate(1, n);
}
