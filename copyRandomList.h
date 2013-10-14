#ifndef COPYRANDOMLIST
#define COPYRANDOMLIST
struct RandomListNode {
  	int label;
	RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(0), random(0){}
};
class Solution {
public:
   RandomListNode* copyRandomList(RandomListNode*);
};
#endif
