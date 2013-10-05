#include "deleteDuplicates.h"

ListNode* Solution::deleteDuplicates(ListNode* head) {
  	if(head == nullptr)
	  	return head;
  	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* pre = dummy;
	ListNode* current = head;
	ListNode* post = current->next;
	while(post != nullptr) {
	  	bool d = false;
		while(post != nullptr && current->val == post->val) {
		  	post = post->next;
			d = true;
		}
		if(d) {
		  	pre->next = post;
			while(current->next != post) {
			  	ListNode* tmp = current;
				current = current->next;
				delete tmp;
			}
			current = post;
			if(current == nullptr)
			  	break;
			post = current ->next;
		} else {
		  	pre = current;
		  	current = post;
			post = current->next;
		}
	}
	head = dummy->next;
	delete dummy;
	return head;
}
