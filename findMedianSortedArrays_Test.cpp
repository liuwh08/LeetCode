#include "findMedianSortedArrays.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {2, 4, 6, 8, 10};
	Solution s;
	cout<<s.findMedianSortedArrays(A, 5, B, 5)<<endl;
	return 0;
}
