#include "divide.h"
#include <cstdlib>

int Solution::divide(int dividend, int divisor_) {
	int neg = 1;
	if((dividend>0)&&(divisor_<0))
		neg = -1;
	if((dividend<0)&&(divisor_>0))
		neg = -1;
	long int divided = dividend;
	long int divisor = divisor_;
	divided = std::abs(divided);
	divisor = std::abs(divisor);
	unsigned int ans = 0;
	unsigned int binary[32];
	int index = 0;
	long int tmp = divisor;
	while(tmp<=divided&&tmp>0) {//tmp>0 is very important to avoid time limit exceeds issue!!
		binary[index++] = tmp;
		tmp = tmp<<1;
	}

	for (int i = index - 1; i >=0; --i)
	{
		if(divided>=binary[i]){
			ans += 1<<i;
			divided -= binary[i];
		}
	}
	return neg*ans;
}
