#include "copyRandomList.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  RandomListNode* head = new RandomListNode(-1);
  Solution s;
  s.copyRandomList(head);
  return 0;
}
