#include "mergeTwoLists.h"

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(l1 == nullptr)
		return l2;
	if(l2 == nullptr)
		return l1;
	ListNode *start_ptr1 = l1, *start_ptr2 = l2;

	ListNode *virtual_head = new ListNode(0);
	ListNode *current = virtual_head;
	while(start_ptr1 != nullptr && start_ptr2 != nullptr) {
		if(start_ptr1->val < start_ptr2->val) {
			current->next = start_ptr1;
			start_ptr1 = start_ptr1 ->next;
			current = current->next;
		}
		else {
			current->next = start_ptr2;
			start_ptr2 = start_ptr2->next;
			current = current->next;
		}
	}
	if(start_ptr1 == nullptr) {
		current->next = start_ptr2;
	}
	else current->next = start_ptr1;

	ListNode* head = virtual_head->next;
	delete virtual_head;
	return head;
}
