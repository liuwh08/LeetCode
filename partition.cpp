#include "partition.h"

ListNode* Solution::partition(ListNode *head, int x) {
  	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode *insertAfter = dummy, *current = head, *pre = dummy;
	while( current ) {
	  	if(current->val >= x) {
		  	pre = current;
		  	current = current->next;
			continue;
		}
		if( insertAfter->next == current ){
		  	insertAfter = insertAfter->next;
			pre = current;
			current = current->next;
			continue;
		}
		pre->next = current->next;
		current->next = insertAfter->next;
		insertAfter->next = current;
		insertAfter = current;
		current = pre->next;
	}
	head = dummy->next;
	delete dummy;
	return head;
}
