#include "TwoSum.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int a[4] = {5, 75, 25};
	vector<int> myints ( a, a + sizeof(a)/sizeof(int));
	Solution s;
	vector<int> res = s.twoSum(myints, 100);
	cout<<res.at(0)<<' '<<res.at(1)<<endl;
	return 0;
}
