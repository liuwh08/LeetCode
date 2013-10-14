#include "maxDepth.h"
#include <vector>

using namespace std;

int Solution::maxDepth(TreeNode* root) {
  	if(!root)
	  	return 0;
	else 
	  	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
