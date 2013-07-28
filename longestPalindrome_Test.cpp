#include "longestPalindrome.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	string str = "abccba";
	cout<<s.longestPalindrome(str)<<endl;
	str = "1jkoppollf";
	cout<<s.longestPalindrome(str)<<endl;
	return 0;
}
