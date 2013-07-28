#include "reverse.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	cout<<s.reverse(123)<<endl;
	cout<<s.reverse(-123)<<endl;
	cout<<s.reverse(0)<<endl;
	cout<<s.reverse(-0)<<endl;
	return 0;
}
