#include "sortedListToBST.h"
#include <vector>

using namespace std;

TreeNode* buildBST(ListNode*& list, int start, int end) {
  	if(start>end) 
	  	return nullptr;
	int mid = (start + end) / 2;
	TreeNode* leftTree = buildBST(list, start, mid - 1);
	TreeNode* root = new TreeNode(list->val);
	list = list->next;
	TreeNode* rightTree = buildBST(list, mid + 1, end);
	root->left = leftTree;
	root->right = rightTree;
	return root;
}

TreeNode* Solution::sortedListToBST(ListNode* head) {
  	if(!head) 
	  	return nullptr;
	int n = 0;
	ListNode* tmp = head;
	while(tmp) {
	  	n++;
		tmp = tmp->next;
	}
	return buildBST(head, 0, n - 1);
}
