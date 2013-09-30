#include "fullJustify.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  	Solution s;
	string myString[] = {"This", "is", "an", "example", "of", "text", "justification."};
	vector<string> tmp(myString, myString + sizeof(myString)/sizeof(string));
	s.fullJustify(tmp , 16);
  	return 0;
}
