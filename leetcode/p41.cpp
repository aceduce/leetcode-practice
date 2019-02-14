# include"Solutions.h"

int p41::firstMissingPositive(vector<int>& nums) {
	// cannot use sort as sort consumes nlogn
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] <= 0)
			nums[i] = INT_MAX; // a lable to mark it
	}
	// reverting
	for (int i = 0; i < nums.size(); i++) { 
		if (abs(nums[i]) <= nums.size()) {  // only need to revert the size
			// need to have abs to compare
			nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0)
			return i + 1;
	}
	return nums.size() + 1;
}