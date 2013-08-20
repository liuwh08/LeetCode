#include "removeNthFromEnd.h"


ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	ListNode *n1, *n2;
	n1 = head;
	n2 = head;
	int i = n;
	while(i>1){
		n2 = n2->next;
		i--;
	}
	if(n2->next == nullptr){
		ListNode *tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}
	ListNode* n1_prev;
	while(n2->next != nullptr) {
		n1_prev = n1;
		n1 = n1->next;
		n2 = n2->next;
	}
	n1_prev->next = n1->next;
	delete n1;
	return head;
}

