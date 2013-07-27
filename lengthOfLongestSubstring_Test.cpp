#include "lengthOfLongestSubstring.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	string str("abcdefa");
	cout<<s.lengthOfLongestSubstring(str)<<endl;
	str = "bbbbbb";
	cout<<s.lengthOfLongestSubstring(str)<<endl;
	str = "abcabcbb";
	cout<<s.lengthOfLongestSubstring(str)<<endl;
	return 0;
}
