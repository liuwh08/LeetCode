#include "swapPairs.h"


ListNode* Solution::swapPairs(ListNode* head) {
	if(head == nullptr)
		return nullptr;
	if(head->next == nullptr)
		return head;
	ListNode *n1 = head, *n2 = head->next;
	n1->next = n2->next;
	head = n2;
	n2->next = n1;
	ListNode *n1_prev = n1;
	n1 = n1->next;
	if(n1!=nullptr)
		n2 = n1->next;
	while((n1!=nullptr)&&(n2!=nullptr)){
		n1->next = n2->next;
		n1_prev->next = n2;
		n2->next = n1;

		n1_prev = n1;
		n1 = n1->next;
		if(n1!=nullptr)
			n2 = n1->next;
	}
	return head;
}

		

