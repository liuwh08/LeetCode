#ifndef REVERSEKGROUP
#define REVERSEKGROUP
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode*, int);
};
#endif
