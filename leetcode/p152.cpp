#include"Solutions.h"
// like P53
// keep max to current, and max
int p152::maxProduct(vector<int>& nums) {
// here use max2cur, min2cur
// max2cur = max(cur, min2cur * cur, max2cur * cur)
// max = max(max, max2cur)
	int size = nums.size();
	if (size == 1) return nums[0];
	int max2cur = nums[0];
	int min2cur = nums[0];
	int ans = nums[0]; //INT_MIN; ==> a mistake!

	for (int i = 1; i < size; i++) {
		int max2cur_o = max2cur;
		int min2cur_o = min2cur;
		max2cur = max( nums[i], max(max2cur_o * nums[i], min2cur_o * nums[i]));
		min2cur = min(nums[i], min(min2cur_o * nums[i], max2cur_o * nums[i]));
		ans = max(ans, max2cur);
	}
	return ans;
}

void p152::test() {

}