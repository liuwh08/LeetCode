#ifndef MERGE
#define MERGE
#include <vector>
struct Interval {
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};
class Solution {
	public:
		std::vector<Interval> merge(std::vector<Interval> &);
};
#endif
