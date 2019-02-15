# include "Solutions.h"
/* this is an iterative question, not recursive!*/
bool subsearch(vector<int>& nums, int left, int right, int target) {
	while (left + 1 < right ) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) return true;
		if (nums[mid] > nums[left]) {
			if (target >= nums[left] && target <= nums[mid]) {
				right = mid;
				//return subsearch(nums, left, mid, target);
			}
			else {
				//return subsearch(nums, mid, right, target);
				left = mid;
			}
		}
		else if (nums[mid] < nums[left]) {
			if (target >= nums[mid] && target <= nums[right]) {
				//return subsearch(nums, mid, right, target);
				left = mid;
			}
			else {
				//return subsearch(nums, left, mid, target);
				right = mid;
			} 
		}
		else left++;
	}
	if (nums[left] == target || nums[right] == target) return true;
	return false;
}


bool p81::search(vector<int>& nums, int target) {
	if (nums.size() == 0) return false;
	return subsearch(nums, 0, nums.size() - 1, target);
	
}

void p81::test() {
	vector<int> input{};
	cout << search(input, 2);
}
