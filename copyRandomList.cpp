#include "copyRandomList.h"
#include <cstddef>
#include <unordered_map>
#include <iostream>

using namespace std;


RandomListNode* Solution::copyRandomList(RandomListNode* head) {
  	if(head == 0) 
	  	return NULL;
	unordered_map<RandomListNode*, RandomListNode*> map;
	//map.insert(make_pair(NULL, NULL));
	RandomListNode* newHead = new RandomListNode(head->label);
	map.insert(make_pair((RandomListNode*) head, newHead));
	RandomListNode* current = head->next;
	RandomListNode* newCurrentPre = newHead;
	while(current) {
	  	cout<<"In the copying preces\n";
	  	RandomListNode* tmp = new RandomListNode(current->label);
		newCurrentPre->next = tmp;
		map.insert(make_pair(current, tmp));
		current = current->next;
		newCurrentPre = newCurrentPre->next;
	}
	current = head;
	RandomListNode* newCurrent = newHead;
	while( current && newCurrent) {
	  	cout<<"Setting the random Porinter\n";
	  	if(current->random)
	  		newCurrent->random = map[current->random];
		else 
		  	newCurrent->random = NULL;
		current = current->next;
		newCurrent = newCurrent->next;
	}
	return newHead;

}
