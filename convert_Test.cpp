#include "convert.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Solution s;
	string str = "PAYPALISHIRING";
	cout<<s.convert(str, 3)<<endl;
	cout<<s.convert(str, 4)<<endl;
	cout<<s.convert(str, 2)<<endl;
	str = "ABC";
	cout<<s.convert(str, 1)<<endl;
	return 0;
}
