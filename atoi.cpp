#include "atoi.h"
#include <cctype>
#include <climits>

using namespace std;

int Solution::atoi(const char* str) {
	while(isspace(str[0]))
		str++;
	int neg = 1;
	if(str[0] == '-')
		neg = -1;
	if(str[0] == '-' || str[0] == '+')
		str++;

	int sum = 0;
	while(isdigit(str[0])){
		if (INT_MAX/10>=sum)
			sum = sum * 10;
		else
			return neg == -1? INT_MIN:INT_MAX;
		int d = str[0] - '0';
		if (INT_MAX - d>=sum)
			sum +=d;
		else
			return neg == -1? INT_MIN:INT_MAX;
		str++;
	}
	return neg*sum;
}
