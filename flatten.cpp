#include "flatten.h"
#include <vector>
#include <iostream>

using namespace std;

TreeNode* tree2link(TreeNode* root) {
  	if(!root)
	  	return root;
	TreeNode* leftTree = tree2link(root->left);
	TreeNode* rightTree = tree2link(root->right);
	root->left = nullptr;
	if(leftTree == nullptr && rightTree == nullptr){
	  	cout<<"Entering Mode 1"<<endl;
	  	return root;
	}
	if(leftTree == nullptr) {
	  	cout<<"Entering Mode 2"<<endl;
	  	root->right = rightTree;
		return root;
	}
	if(rightTree == nullptr) {
	  	cout<<"Entering Mode 3"<<endl;
	  	root->right = leftTree;
		return root;
	}
	cout<<"Entering Mode 4"<<endl;
	root->right = leftTree;
	TreeNode* tmp = leftTree;
	while(tmp->right) {
	  	tmp = tmp->right;
	}
	tmp->right = rightTree;
	return root;
}

void Solution::flatten(TreeNode* root) {
  	root = tree2link(root);
}
