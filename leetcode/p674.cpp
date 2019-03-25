#include"Solutions.h"
class p674::Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int s = nums.size();
		if (s == 0) return 0;
		int ans = 1;
		vector<int> DP(s + 1, 1);
		for (int i = 1; i < s; i++) {
			if (nums[i] > nums[i - 1]) {
				DP[i] = DP[i - 1] + 1;
			}
			else DP[i] = 1;
			if (ans < DP[i])
				ans = DP[i];
		}
		return ans;
	}
};
/* Sliding window method!:
class Solution {
	public int findLengthOfLCIS(int[] nums) {
		int ans = 0, anchor = 0;
		for (int i = 0; i < nums.length; ++i) {
			if (i > 0 && nums[i-1] >= nums[i]) anchor = i;
			ans = Math.max(ans, i - anchor + 1);
		}
		return ans;
	}
}
*/