#include "romanToInt.h"
#include <map>

using namespace std;

int Solution::romanToInt(string s) {
	map<char,int> c2n;
	c2n.insert(make_pair('M', 1000));
	c2n.insert(make_pair('D', 500));
	c2n.insert(make_pair('C', 100));
	c2n.insert(make_pair('L', 50));
	c2n.insert(make_pair('X', 10));
	c2n.insert(make_pair('V', 5));
	c2n.insert(make_pair('I', 1));
	c2n.insert(make_pair('A', 0));

	int i = 0;
	int sum = 0;
	s.append("A");
	while(i<s.length() - 1) {
		if(c2n.at(s.at(i))<c2n.at(s.at(i+1)))
			sum -= c2n.at(s.at(i));
		else
			sum += c2n.at(s.at(i));	
		i++;
	}
	return sum;
}	
