#include "mergeKLists.h"

using namespace std;

ListNode* Merge(ListNode* l1, ListNode* l2) {
	if(l1==nullptr)
		return l2;
	if(l2==nullptr)
		return l1;
	ListNode* tail = nullptr;
	ListNode* tmp = nullptr;
	if(l1->val<l2->val){
		tail = new ListNode(l1->val);
		tmp = l1;
		l1 = l1->next;
		delete tmp;
	}else {
		tail = new ListNode(l2->val);
		tmp = l2;
		l2 = l2->next;
		delete tmp;
	}
	ListNode* head = tail;
	while((l1 != nullptr)&&(l2!=nullptr)) {
		if(l1->val<l2->val){
			tail->next = new ListNode(l1->val);
			tmp = l1;
			l1 = l1->next;
			delete tmp;
			tail = tail->next;
		}else {
			tail->next = new ListNode(l2->val);
			tmp = l2;
			l2 = l2->next;
			delete tmp;
			tail = tail->next;
		}
	}
	ListNode* non_empty;
	if(l1==nullptr)
		non_empty = l2;
	else non_empty = l1;
	while(non_empty != nullptr){
		tail->next = new ListNode(non_empty->val);
		tmp = non_empty;
		non_empty = non_empty->next;
		delete tmp;
		tail = tail->next;
	}
	return head;
}

ListNode* Solution::mergeKLists(vector<ListNode*> & lists) {
	if(lists.size() == 0)
		return nullptr;
	ListNode* head = lists[0];
	for (int i = 1; i < lists.size(); ++i)
	{
		head = Merge(head, lists.at(i));
	}
	return head;
}
	
