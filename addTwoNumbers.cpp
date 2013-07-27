#include "addTwoNumbers.h"

int get_val(ListNode* l){
	if(l==nullptr)
		return 0;
	else
		return l->val;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = nullptr;
        ListNode* tail = nullptr;
	head = new ListNode((get_val(l1)+get_val(l2))%10);
	tail = head;
	int carry = (get_val(l1)+get_val(l2))/10;
	l1 = get_next(l1);
	l2 = get_next(l2);
	while((l1 != nullptr)||(l2 != nullptr)||(carry!=0)){
		int sum = get_val(l1) + get_val(l2) + carry;
		tail->next = new ListNode(sum%10);
		carry = sum/10;
		tail = tail->next;	
		l1 = get_next(l1);
		l2 = get_next(l2);
	}
	return head;
}

ListNode* get_next(ListNode* l) {
	if(l==nullptr)
		return nullptr;
	else
		return l->next;
}

