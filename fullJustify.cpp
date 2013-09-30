#include "fullJustify.h"
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> Solution::fullJustify(vector<string> &words, int L) {
  	vector<string> res;
	if(L==0){
	  	res.push_back(string(""));
		return res;
	}
	vector<string> tmp;
	int i = 0;
	while(1) {
	  	string line = "";
		int current_words_length = 0;
		int j = i;
		while(j< words.size() && (current_words_length + words[j].size() <= L - (j - i))) {
		  	current_words_length += words[j].size();
		  	j++;
		}
		int num_words = j - i;
		if(num_words == 1) {
		  	line.append(words[i]);
			line.append(L - words[i].length(), ' ');
			i = j;
		} else {
			if(j==words.size()) {
				for (int k = i; k < j; ++k)
				{
		  			line.append(words[k]);
					if(k<j-1)
						line.append(1, ' ');
				}
		  			line.append(L - current_words_length - num_words + 1, ' ');
			}
			else {
				for (int k = i; k < j; ++k)
				{
		  			line.append(words[k]);
					if(k<j-1) {
						line.append((L - current_words_length)/(num_words-1), ' ');
						if(k-i<(L - current_words_length) % (num_words - 1))
						  	line.append(1, ' ');
					}
				}
			}
			i = j;
		}
		//cout<<line<<endl;
		res.push_back(line);
		if(i==words.size())
		  	break;
	}
	return res;
}
