#include "isPalindrome.h"


bool Solution::isPalindrome(int x) {
	if(x<0)
		return false;
	long int s = 1, x_back = x;
	while(x>0) {
		s = 10*s;
		x = x_back/s;
	}
	s = s/10;
	std::cout<<"s = "<<s<<std::endl;
	int p = 1, q = s;
	x = x_back;
	while(s>=p) {
		int l = x % 10;
		int r = x/q;
		x = x - (r * q);
	        x = x/10;
		p = p * 10;
		s = s/10;
		q = q/100;
		std::cout<<"x: "<<x<<' '<<l<<' '<<r<<std::endl;
		if(l != r)
			return false;	
	}
	return true;
}

