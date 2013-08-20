#ifndef MERGEKLISTS
#define MERGEKLISTS 
#include <vector>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode* > & lists);
};
#endif
