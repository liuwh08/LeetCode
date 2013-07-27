#ifndef ADDTWONUMBERS_H
#define ADDTWONUMBERS_H 
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode*, ListNode*);
};
int get_val(ListNode*);
ListNode* get_next(ListNode*);

	
#endif
