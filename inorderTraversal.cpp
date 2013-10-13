#include "inorderTraversal.h"
#include <stack>

using namespace std;

vector<int> Solution::inorderTraversal(TreeNode* root) {
  	stack< pair<TreeNode*, bool> > s;
	vector<int> res;
	if(!root)
	  	return res;
	if(root->right) 
	  	s.push(make_pair(root->right, false));
	s.push(make_pair(root, true));
	if(root->left)
	  	s.push(make_pair(root->left, false));
	while(!s.empty()) {
	  	auto current = s.top();
		s.pop();
		if(current.second) {
		  	res.push_back(current.first->val);
			continue;
		} else {
		  	if(current.first->right)
			  	s.push(make_pair(current.first->right, false));
			s.push(make_pair(current.first, true));
		  	if(current.first->left)
			  	s.push(make_pair(current.first->left, false));
		}
	}
	return res;
}
