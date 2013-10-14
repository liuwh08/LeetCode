#include "levelOrder.h"
#include <queue>

using namespace std;

vector<vector<int> > Solution::levelOrder(TreeNode* root) {
  	vector<pair<TreeNode*, int> > q;
	vector<vector<int> > res;
	if(root == nullptr)
	  	return res;
	q.push_back(make_pair(root, 0));
	int front = 0;
	while(front<q.size()) {
	  	auto current = q[front++];
	  	TreeNode* current_node = current.first;
		int current_layer = current.second;
		if( current_node->left) 
		  	q.push_back(make_pair(current_node->left, current_layer + 1));
		if( current_node->right)
		  	q.push_back(make_pair(current_node->right, current_layer + 1));
	}
	int current_layer = 0;
	vector<int> tmp(1, root->val);
	for(auto i = q.begin() + 1; i != q.end(); ++i) {
	  	if( (*i).second > current_layer) {
		  	res.push_back(tmp);
			tmp.clear();
			current_layer = (*i).second;
		}
		tmp.push_back((*i).first->val);
	}
	res.push_back(tmp);
	return res;
}
