#include"Solutions.h"
int p414::thirdMax(vector<int>& nums) {
	if (nums.size() < 3) return *max_element(nums.begin(), nums.end());
	priority_queue<int, vector<int>, greater<int>> pq; // min-heap Nlog(3)
	for (auto const & num : nums) {
		pq.push(num);
		if (pq.size() > 3) pq.pop();
	}
	return pq.top();
}