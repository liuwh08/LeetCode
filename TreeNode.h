#ifndef TREENODE_H_
#define TREENODE_H_
struct TreeNode {
  	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(0), right(0) {}
};
#endif
