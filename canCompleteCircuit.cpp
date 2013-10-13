#include "canCompleteCircuit.h"

using namespace std;

int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  	int current_sum_gas = 0, sum_gas = 0;
	int index = -1;
	for (int i = 0; i < gas.size() ; ++i){
	  	current_sum_gas += gas[i] - cost[i];
		sum_gas += gas[i] - cost[i];
		if(current_sum_gas < 0) {
		  	index = i;
			current_sum_gas = 0;
		}
	}
  	
  	return sum_gas<0 ? -1 : index + 1;
}
