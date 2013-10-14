#include "flatten.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  TreeNode* root = new TreeNode(1);
  TreeNode* right = new TreeNode(5);
  TreeNode* left = new TreeNode(2);
  root->right = right;
  root->left = left;
  Solution s;
  s.flatten(root);
  cout<< root->val << root->right->val << root->right->right->val;
  delete right;
  delete root;
  return 0;
}
