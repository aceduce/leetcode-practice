#include"Solutions.h"

// start: new_start < interval end ==> start reset with the min
// end: new_end > interval_start ==> end reset with the max
// the above rules apply for both btw and separate cases
vector<Interval> p57::insert(vector<Interval>& intervals, Interval newInterval) {

	vector<Interval> ans;
	if (intervals.size() == 0) {
		ans.push_back(newInterval);
		return  ans;
	}
	int i = 0;
	// three separate senarios loop!!
	while (i < intervals.size() && intervals[i].end < newInterval.start) {
		ans.push_back(intervals[i]);
		i++;
	}
	while (i < intervals.size() &&  intervals[i].start <= newInterval.end) {
		// key is still updating the new inteval!!! not just start and end
		
		//int start = min(intervals[i].start, newInterval.start);
		//int end = max(intervals[i].end, newInterval.end);

		newInterval.start = min(intervals[i].start, newInterval.start);
		newInterval.end = max(intervals[i].end, newInterval.end);
		i++;
	} 
	ans.push_back(newInterval);
	while (i < intervals.size()) {
		ans.push_back(intervals[i]);
		i++;
	}
	return ans;
}

void p57::test() {

}