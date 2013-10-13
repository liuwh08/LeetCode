#include "reverseBetween.h"

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
  	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	int count = m;
	ListNode* current = head;
	ListNode* prep = dummy;
	while(--count>0){
	  	prep = current;
	  	current = current->next;
	}
	ListNode* tail = current;
	int nToReverse = n - m + 1;
	while(--nToReverse>0) {
	  	ListNode* nextToReverse = tail->next;
		tail->next = nextToReverse->next;
		nextToReverse->next = current;
		current = nextToReverse;
	}
	prep->next = current;
	head = dummy->next;
	delete dummy;
	return head;
}
