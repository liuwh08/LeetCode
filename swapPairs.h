#ifndef SWAPPAIRS
#define SWAPPAIRS 
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode *head);
};
#endif
