#include "reverseKGroup.h"

using namespace std;

void SwapNodes(ListNode* n1, ListNode* n2, ListNode* n1_prev, ListNode* n2_prev) {
	ListNode* tmp = n1->next;
	n1->next = n2->next;
	n2->next = tmp;
	n1_prev->next = n2;
	n2_prev->next = n1;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
	if(k<=1)
		return head;
	ListNode *virtual_head = new ListNode(0);
	virtual_head->next = head;
	ListNode* n1 = head;
	ListNode* n1_prev = virtual_head;
	ListNode* n2 = head;
	ListNode* n2_prev;
	bool isEnough = true;
	for (int i = 1; i < k; ++i)
	{
		if(n2 == nullptr) {
			isEnough = false;
			break;
		}
		n2_prev = n2;
		n2 = n2->next;
	}
	if(!isEnough)
		return head;

	int start = 0;
	int end = k - 1;
	
