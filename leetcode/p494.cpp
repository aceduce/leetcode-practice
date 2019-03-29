#include"Solutions.h"
class p494::Solution_BF {
	// use back-tracking
public:
	void subSumWays(vector<int> & nums, int indx, int S, int & sum, int & ans) {
		int n = nums.size();
		if (indx == n) {
			if (sum == S)
				ans++;
			return;
		}
		int tmp = sum;
		// try +
		sum += nums[indx];
		subSumWays(nums, indx + 1, S, sum, ans);
		sum = tmp - nums[indx];
		subSumWays(nums, indx + 1, S, sum, ans);
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		if (n == 0) return 0;
		int sum = 0, ans = 0;
		subSumWays(nums, 0, S, sum, ans);
		return ans;
	}
};


class p494::Solution {
	// use back-tracking
public:
	void subSumWays(vector<int> & nums, int indx, int S, int & sum, int & ans) {
		int n = nums.size();
		if (indx == n) {
			if (sum == S)
				ans++;
			return;
		}
		int tmp = sum;
		// try +
		sum += nums[indx];
		subSumWays(nums, indx + 1, S, sum, ans);
		sum = tmp - nums[indx];
		subSumWays(nums, indx + 1, S, sum, ans);
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		if (n == 0) return 0;
		int sum = 0, ans = 0;
		subSumWays(nums, 0, S, sum, ans);
		return ans;
	}
};