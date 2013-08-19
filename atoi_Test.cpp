#include "atoi.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	cout<<s.atoi("123")<<endl;
	cout<<s.atoi("-123")<<endl;
	cout<<s.atoi("0")<<endl;
	cout<<s.atoi("-0")<<endl;
	cout<<s.atoi("2147483648")<<endl;
	return 0;
}
