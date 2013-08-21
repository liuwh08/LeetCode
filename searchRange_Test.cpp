#include "searchRange.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	int A[] = {1};
	cout<<s.searchRange(A, 1, 0).empty();
	return 0;
}
