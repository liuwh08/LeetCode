#include "isPalindrome.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	cout<<s.isPalindrome(123321)<<endl;
	cout<<s.isPalindrome(-1)<<endl;
	cout<<s.isPalindrome(131)<<endl;
	cout<<s.isPalindrome(1)<<endl;
	cout<<s.isPalindrome(12321)<<endl;
	cout<<s.isPalindrome(2147483647)<<endl;
	return 0;
}
