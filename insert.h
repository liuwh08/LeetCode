#ifndef insert
#define insert
struct Interval {
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#include <vector>
class Solution {
public:
	std::vector<Interval> insert(std::vector<Interval> &, Interval);
};
#endif
