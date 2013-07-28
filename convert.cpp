#include "convert.h"

using namespace std;

string Solution::convert(string s, int nRows) {
	if(nRows == 1)
		return s;
	string* rows_of_string = new string[nRows];
	string::iterator i = s.begin();
	int row_index = 0;
	int reverse = 1;
	while(i!=s.end()){
		rows_of_string[row_index] += *i;
		row_index += reverse;
		if (row_index==nRows)
		{
			reverse = -1;
			row_index = nRows - 2;
		}
		if (row_index==-1)
		{
			reverse = 1;
			row_index = 1;
		}
		i++;
	}
	string result = "";
	for (int j = 0; j < nRows; ++j)
	{
		result += rows_of_string[j];
	}
	delete []rows_of_string;
	return result;
}


				
