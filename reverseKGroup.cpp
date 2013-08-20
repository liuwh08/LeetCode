#include "reverseKGroup.h"


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
	if(head==nullptr)
		return head;
	ListNode *virtual_head = new ListNode(0);
	virtual_head->next = head;
	ListNode* prev = virtual_head, *current = head, *post = head->next;
	while(current!=nullptr) {
		int i = 0;
		post = current->next;
		while((i<k-1)&&(post !=nullptr)) {
			ListNode* tmp = post->next;
			post->next = current;
			current = post;
			post = tmp;
			i++;
		}
		if(i<k-1) {
			ListNode* tmp = post;
			post = current;
			current = tmp;
			int j = 0;
			while(j<i) {
				tmp = post->next;
				post->next = current;
				current = post;
				post = tmp;
				j++;
			}
			break;
		}
		ListNode* tmp = prev->next;
		prev->next = current;
		tmp->next = post;
		prev = tmp;
		current = post;
	}
	ListNode* res = virtual_head->next;
	delete virtual_head;
	return res;
}

