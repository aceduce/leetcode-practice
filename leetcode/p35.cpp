# include"Solutions.h"

int p35::searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int left = 0, right = n - 1;
	while (left + 1< right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		if (nums[mid] < target) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	// end of the loop senarios:
	// left two nums: left and right
	if (nums[left] >= target) return left;
	if (nums[right] <= target) return right + 1;
	if (nums[left] < target) return right;
	// return -1;
}