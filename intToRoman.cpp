#include "intToRoman.h"

using namespace std;

string Solution::intToRoman(int num) {
	const string huns[]={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	const string tens[]={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	const string ones[]={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

	string res = "";
	while(num>=1000) {
		res.append("M");
		num -= 1000;
	}
	res.append(huns[num/100]);
	num = num % 100;
	res.append(tens[num/10]);
	num = num % 10;
	res.append(ones[num]);
	
	return res;
	
}	
