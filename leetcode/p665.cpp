#include"Solutions.h"
// O(N) solution by scanning through the whole array
// find the pattern (appears <=1)
bool p665::checkPossibility(vector<int>& nums) {
	int n = nums.size();
	int p = -1;
	for (int i = 0; i < n - 1; i++) {
		if (nums[i] >  nums[i + 1]) {
			if (p != -1) { // a duppicate issue
				return false;
			}
			p = i;
		}
	}
	if (p == 0 || p == n - 2) // first and last element can be tuned
		return true;
	if (p == -1) return true; // no element needs to be tuned
	if (nums[p - 1] <= nums[p + 1] // tune p
		|| nums[p] <= nums[p + 2]) // tune p + 1
		return true;
	else
		return false;
}