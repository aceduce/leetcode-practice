#include"Solutions.h"
// solve it in linear time
// multiple solutions from huahua
// https://www.youtube.com/watch?v=2SXqBsTR6a8

class p239::MonotonicQueue {
public:
	void push(int e) {
		while (!data_.empty() && e > data_.back()) data_.pop_back();
		data_.push_back(e);
	}
	void pop() {
		data_.pop_front(); // O(1) complexity
	}
	int max() const { return data_.front(); }

private:
	deque<int> data_;
	// deque ordering in descending order
	// vector pop front use O(1) time
};

vector<int> p239::maxSlidingWindow_monotonic_queue(vector<int>& nums, int k) {
	MonotonicQueue q;
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		q.push(nums[i]);
		if (i - k + 1 >= 0) {
			ans.push_back(q.max());
			if (nums[i - k + 1] == q.max()) q.pop();
			// only need to pop when q.max
			// slideing window <= window size
		}
	}
	return ans;
}

// a Simplified version of this...
// only using deck, a optimization from above
vector<int> p239::maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	deque<int> index;
	for (int i = 0; i < nums.size(); i++) {
		while (!index.empty() && nums[index.back()] <= nums[i]) index.pop_back(); // like a monotonic queue
		index.push_back(i);
		if (i - k + 1 >= 0) // insert max
			ans.push_back(nums[index.front()]);
		if (i - k + 1  == index.front()) index.pop_front();
	}
	return ans;
}

vector<int> p239::maxSlidingWindow_brute_force(vector<int>& nums, int k) {
	vector<int> ans;
	for (int i = k - 1; i < nums.size(); i++) {
		ans.push_back(*max_element(nums.begin() + i - k + 1, nums.begin() + i + 1)); 
		// right side iterator doesn't include
	}
	return ans;
}

vector<int> p239::maxSlidingWindow_multisetBFS(vector<int>& nums, int k) {
	// BFS
	vector<int> ans;
	multiset<int> window;
	for (int i = 0; i < nums.size(); i++) { // add into BFS
		window.insert(nums[i]);
		if (i - k + 1 >= 0) {
			ans.push_back(*window.rbegin());
			// cannot use erase by key
			window.erase(window.equal_range(nums[i - k + 1]).first);
			// cannot use window.erates(nums[i - k + 1]);
		}
	}
	return ans;
}

void p239::test() {
	// like a queue, but better?
	deque<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(8);
	q.push_back(3);

	// BFS Ascending order
	multiset<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(5);
	s.insert(10);
	s.insert(8);

}