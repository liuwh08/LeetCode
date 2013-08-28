#ifndef ROTATERIGHT
#define ROTATERIGHT
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x) {}
};
class Solution {
public:
	ListNode* rotateRight(ListNode*, int);
};
#endif
