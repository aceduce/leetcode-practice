#include "Solutions.h"

// two pointer solutions
// think about a template for binary search!
int p33::search(vector<int>& nums, int target) {
	if (nums.empty()) return -1; // NULL means zero
	int n = nums.size();
	int left = 0, right = n - 1;
	int mid;
	while (left + 1 < right) { // if using left < right, would be a forever loop?
		mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		if (nums[mid] >= nums[left]) { // mid point on right
			if (target <= nums[mid] && target >= nums[left]) {
				right = mid;
			}
			else { left = mid;  }
		}
		else { // mid-point on right
			if (target <= nums[right] && nums[mid] <= target) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
	}
	// separtely check left and right pinters
	if (nums[left] == target) return left; 
	if (nums[right] == target) return right;
	return -1;
}