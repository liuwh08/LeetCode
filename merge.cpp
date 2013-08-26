#include "merge.h"
#include <cstdlib>

using namespace std;

void Insert(Interval & a, vector<Interval> & intervals) {
	bool overlap = false;
	Interval current = a;
	while(1) {
		for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end() ; ++i)
		{
			if((current.start > (*i).end) || (current.end < (*i).start)) 
				continue;
			overlap = true;
			current.start = min(current.start, i->start);
			current.end = max(current.end, i->end);
			break;
		}
		if(!overlap)
			break;
	}
	intervals.push_back(current);
}

vector<Interval> Solution::merge(vector<Interval>& intervals) {
	vector<Interval> res;
	for (int i = 0; i < intervals.size() ; ++i)
	{
		Insert(intervals[i], res);
	}
	return res;
}
