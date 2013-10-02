#include "simplyfyPath.h"
#include <vector>
#include <iostream>

using namespace std;

string Solution::simplyPath(string path) {
  	vector<string> stack;
//	cout<<path<<endl;
	for (int i = 0; i < path.size() ; ++i){
	  	//cout<<"i = "<<i<<endl;
	  	int j = i;
		if(path[i] == '/')
		  	continue;
		while(j < path.size() && path[j] != '/')
		  	j++;
		string sub = path.substr(i, j-i);
		i = j;
		//cout<<sub<<endl;
		if(sub == ".")
		  	continue;
		if(sub == ".."){
		  	if(! stack.empty() )
			  	stack.pop_back();
			continue;
		}
		stack.push_back(sub);
	}
	string res;
	for (int i = 0; i < stack.size() ; ++i){
	  	res += "/" + stack[i];
	}
	if(res == "")
	  	res = "/";
	return res;
}
