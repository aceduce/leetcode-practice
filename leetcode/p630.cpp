#include"Solutions.h"
// choose the heap solution & a easier solution (max sub support)
// https://leetcode.com/problems/course-schedule-iii/solution/
int p630::scheduleCourse(vector<vector<int>>& courses) {
	int n = courses.size();
	// labmda function for sort!!
	sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1];});
	priority_queue<int> max_heap; // c++ default priority queue
	int count = 0, time = 0;
	for (int i = 0; i < n; i++) {
		if (time + courses[i][0] <= courses[i][1]) { // can be inserted as valid time
			max_heap.push(courses[i][0]); // will always get the highest value
			time += courses[i][0];
			count++;
		}
		else { // remove the big blocker
			if (!max_heap.empty() && max_heap.top() > courses[i][0]) { // swap, take the coures and reaplce it
				time += courses[i][0] - max_heap.top();
				max_heap.pop();
				max_heap.push(courses[i][0]);
			}
		}
	}
	return count;
}

class p630::p630_Solution {
public:
	struct comparator {
		bool operator()(const vector<int>& v1, const vector<int>& v2) {
			return v1[1] < v2[1];
		}
	};
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), comparator());

		// Priority Queue by default sorted in MAX HEAP ORDER
		priority_queue<int> q;

		int sum = 0;
		for (auto& c : courses)
		{
			int t = c[0]; //Course time
			int d = c[1]; //Max day before which course has to be completed

			q.push(t);
			sum += t;

			if (sum > d)
			{
				sum -= q.top(); //This can be some other long course
				q.pop();
			}

		}
		return q.size();
	}
};
void p630::test() {

}