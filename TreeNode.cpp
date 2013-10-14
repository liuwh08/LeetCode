#include "TreeNode.h"
#include <vector>

using namespace std;

bool isTwoSymmetric(TreeNode* p, TreeNode* q) {
  	if( p == nullptr && q == nullptr) 
	  	return true;
	if( p == nullptr || q == nullptr)
	  	return false;
	if( p->val != q->val) 
	  	return false;
	return isTwoSymmetric(p->left, q->right) && isTwoSymmetric(p->right, q->left);
}

bool Solution::isSymmetric(TreeNode* root) {
  	if( root == nullptr) 
	  	return true;
	return isSymmetric(
}
