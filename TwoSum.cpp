#include "TwoSum.h"
#include <set>

using namespace std;

vector<int> Solution::twoSum(vector<int>& numbers, int target){
	set<int> s;
	for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i){
		s.insert(*i);
	}
	int j = 0;
	int index1 = 0, index2 = 0;
	for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i) {
		j = target - (*i);
		if(s.find(j) != s.end()) {
			index1 = i - numbers.begin();
			break;
		}
	}
	for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i) 
		if ((*i)==j)
		{
			index2 = i - numbers.begin();
		}
	vector<int> solu;
	solu.push_back(index1 + 1);
	solu.push_back(index2 + 1);
	return solu;
}



			
