#include"Solutions.h"
class p312::Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		// padding
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		// DP matrix
		vector<vector<int>> dp (n + 2, vector<int>(n + 2, 0));
		return maxC(nums, 1, n);
	}
private:
	int maxC(const vector<int> & nums, const int i, const int j) {
		if (i > j) return 0;
		if (dp[i][j] > 0)
			return dp[i][j];
		if (i == j) { // remove single element
			return nums[i - 1] * nums[i] * nums[i + 1];
		}
		int ans = 0;
		for (int k = i; k <= j; k++) {
			ans = max(ans, maxC(nums, i, k - 1) + nums[i - 1] * nums[k] * nums[j - 1] + maxC(nums, k + 1, j));
			dp[i][j] = ans;
		}
		return dp[i][j];
	}
	vector<vector<int>> dp;
};