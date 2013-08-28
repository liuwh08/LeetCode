#include "insert.h"

using namespace std;


vector<Interval> Solution::insert(vector<Interval> & intervals, Interval a) {
	bool overlap = false;
	Interval current = a;
	while(1) {
		overlap = false;
		for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end() ; ++i)
		{
			if((current.start > (*i).end) || (current.end < (*i).start)) 
				continue;
			overlap = true;
			current.start = min(current.start, i->start);
			current.end = max(current.end, i->end);
			intervals.erase(i);
			break;
		}
		if(!overlap)
			break;
	}
	intervals.push_back(current);
	return intervals;
}

