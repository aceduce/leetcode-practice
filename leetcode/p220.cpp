#include"Solutions.h"
// sliding window and then compare the new element gap
 bool p220::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	 int n = nums.size();
	 for (int i = 0; i <= n - k; i++) {
		 // index [i, i + k - 1]
		 int gap = 0;
		 if (i == 0) {// sort the first k elment and traverse
			 sort(nums.begin(), nums.begin() + k); // last element not inclusive
			 for (int l = 0; l < k - 1; l++) {
				 if (nums[l + 1] = nums[l] <= t)
					 return true;
			 }
		 }
		 else {
			 for (int l = i; l <= i + k - 2; l++) {
				 if (abs(nums[l] - nums[i + k - 1]) <= t)
					 return true;
			 }
		 }
		 return false;
	}
}


 void p220::test() {

 }