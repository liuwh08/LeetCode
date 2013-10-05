#include "deleteDuplicates.h"

ListNode* Solution::deleteDuplicates(ListNode* head) {
  	if(head == nullptr) 
	  	return head;
	//ListNode* pre = dummy;
	ListNode* post = head->next, *current = head;
	while(post != nullptr) {
	  	if(post->val == current->val) {
		  	current->next = post->next;
			delete post;
			post = current->next;
		} else {
		  	current = post;
			post = current->next;
		}
	}
	return head;
}
