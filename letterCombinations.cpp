#include "letterCombinations.h"

using namespace std;

void StringGenerator(string& digits, int depth, vector<string>& res, string* table, string& current) {
	if(depth == digits.length()){
		res.push_back(current);
		return;
	}
	else{
		int i = digits.at(depth) - '0';
		for (int j = 0; j < table[i].length(); ++j)
		{
			current.push_back(table[i].at(j));
			StringGenerator(digits, depth + 1, res, table, current);
			current.resize(current.size() - 1);
		}
	}
}


vector<string> Solution::letterCombinations(string digits) {
	string table[] = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> res;
	string current = "";
	StringGenerator(digits, 0, res, table, current);
	return res;
}
