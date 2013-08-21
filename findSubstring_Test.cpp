#include "findSubstring.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> L(1, "a");
	string S = "a";
	Solution s;
	vector<int> ans = s.findSubstring(S, L);
	cout<<ans.empty()<<endl;
	return 0;
}
