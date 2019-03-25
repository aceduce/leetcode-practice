#include"Solutions.h"
// could use DP method, but O(n^2)
// here, use Greedy method
class p334::Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int min1 = INT_MAX, min2 = INT_MAX;
		int size = nums.size();
		if (size <= 2) return false;
		for (int i = 0; i < size; i++) {
			int val = nums[i]; 
			// case 3
			if (val > min2) return true;
			// case 1
			else if (val < min1) min1 = val;
			else if (val < min2 && val > min1) min2 = val;
		}
		return false;
	}
};