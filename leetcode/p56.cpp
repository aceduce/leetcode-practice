#include"Solutions.h"
// very important 
// 扫描线算法

// more effcient method (from Csp)
// https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
// lambda expression for compartor


bool comp(const Interval &a, const Interval &b) {
	return a.start < b.start;
}

vector<Interval> p56::merge(vector<Interval>& intervals) {
// more intuitive version
	vector<Interval> ans;
	if (intervals.empty()) return ans;
	if (intervals.size() <= 1) return intervals;
	sort(intervals.begin(), intervals.end(), comp);
	
	int start = intervals[0].start;
	int end = intervals[0].end;
	for (int i = 0; i < intervals.size(); i++) {
		if (intervals.at(i).start <= end) {
			end = max(end, intervals.at(i).end);
		}
		else {
			ans.push_back(Interval{ start, end });
			start = intervals[i].start;
			end = intervals[i].end;
		}
	}
	ans.push_back(Interval{ start, end });
	return ans;
}

// my attempt: not very efficent:
vector<Interval> p56::merge_my(vector<Interval>& intervals) {
// need sorting??
	vector<Interval> ans;
	if (intervals.empty()) return ans;
	if (intervals.size() == 1) return intervals;
	vector<int> start; 
	vector<int> end;
	for (int i = 0; i < intervals.size(); i++) {
		start.push_back(intervals[i].start);
		end.push_back(intervals[i].end);
	}
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	int s = start[0], e = end[0];
	for (int i = 1; i < intervals.size(); i++) {
		int begin = s;
		while (i < intervals.size() && start[i] <= e) { // change the ending 
			e = end[i];
			i++;
		}
		Interval tmp{ begin, e }; // valid
		ans.push_back(tmp);
		if (i == intervals.size()) return ans;
		s = start[i];
		e = end[i];
		if (i == intervals.size() - 1) { // last element
			ans.push_back(Interval{ s, e });
			return ans;
		}
	} // the last element
	return ans;
}

void p56::test() {
	vector<Interval> input;
	input.push_back(Interval{ 1,4 });
	input.push_back(Interval{ 4,5 });
	vector<Interval> ans = merge(input);
	for (int i = 0; i < ans.size(); i++) {
		cout << "[" << ans[i].start << " , " << ans[i].end << "]" << endl;
	}
}