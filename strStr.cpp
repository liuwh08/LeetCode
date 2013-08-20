#include "strStr.h"
#include <cstring>

char* Solution::strStr(char *haystack, char *needle) {
	char *str = haystack;
	if((*str == '\0')&&(*needle == '\0'))
		return str;
	if(*str == '\0')
		return nullptr;
	int n = strlen(haystack);
	int m = strlen(needle);
	int left = n;
	while((*str != '\0')&&(left>=m)) {
		char *str1 = str, *str2 = needle;
		while((*str1==*str2)&&(*str1 != '\0')&&(*str2 !='\0')){
			str1++;
			str2++;
		}
		if(*str2 == '\0')
			return str;
		str++;
		left--;
	}
	return nullptr;
}


