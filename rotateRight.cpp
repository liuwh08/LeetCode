#include "rotateRight.h"

ListNode* Solution::rotateRight(ListNode* head, int k) {
	if(k==0)
		return head;
	if(head == nullptr)
		return nullptr;
	ListNode* tmp = head;
	int n = 1;
	while(tmp->next != nullptr) {
		n++;
		tmp = tmp->next;
	}
	tmp->next = head;
	ListNode* new_head = head;
	ListNode* head_prev = tmp;
	k = k % n;
	k = n - k;
	while(k>0) {
		head_prev = new_head;
		new_head = new_head->next;
		k--;
	}
	head_prev->next = nullptr;
	return new_head;
}
