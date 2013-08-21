#include "nextPermutation.h"

using namespace std;

void Solution::nextPermutation(vector<int>& num) {
	int patition = -1;
	int tmp;
	for (int i = num.size()-1; i > 0; --i)
	{
		if(num[i]>num[i-1]){
			patition = i - 1;
			break;
		}
	}
	if(patition>=0){
	int swap_index = 0;
	for(int i = num.size() - 1; i> patition; i--) {
		if(num[i]>num[patition]){
			swap_index = i;
			break;
		}
	}

	tmp = num[swap_index];
	num[swap_index] = num[patition];
	num[patition] = tmp;
	}

	int start = patition + 1;
	int end = num.size() - 1;
	while(start < end) {
		tmp = num[start];
		num[start] = num[end];
		num[end] = tmp;
		start ++;
		end --;
	}
}


