#ifndef REMOVENTHFROMEND
#define REMOVENTHFROMEND 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n);
};
#endif
