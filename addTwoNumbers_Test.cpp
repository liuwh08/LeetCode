#include "addTwoNumbers.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l2 = nullptr;
	ListNode* l3 = s.addTwoNumbers(l1, l2);
	while(l3!=nullptr){
		cout<<l3->val<<"->";
		l3 = get_next(l3);
	}
	return 0;
}
