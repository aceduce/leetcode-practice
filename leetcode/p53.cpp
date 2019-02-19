#include"Solutions.h"

// this is actually a DP problem!
// DP mehtod
int p53::maxSubArray_DP(vector<int>& nums) {
	int len = nums.size();
	vector<int> DP(len + 1);
	DP[0] = 0, DP[1] = nums[0];
	int ans = INT_MIN;
	for (int i = 1; i <= len; i++) {
		DP[i] = max(nums[i - 1], nums[i - 1] + DP[i - 1]);
		ans = (ans > DP[i]) ? ans : DP[i];
	}
	return ans;
}

// using Divid and conquer
int p53::subMaxSub(int left, int right, vector<int> & num) {
	if (left == right) return num[left];
	int m = (left + right) / 2;
	int max_l = subMaxSub(left, m, num);
	int max_r = subMaxSub(m + 1, right, num);
	int leftm = INT_MIN, rightm = INT_MIN;
	int left_sum = 0, right_sum = 0;
	for (int i = m; i >= 0; i--) {
		left_sum += num[i];
		if (left_sum > leftm) leftm = left_sum;
	}
	for (int i = m + 1; i <= right; i++) {
		right_sum += num[i];
		if (right_sum > rightm) rightm = right_sum;
	}
	return max(max(max_l, max_r), rightm + leftm);
}

int p53::maxSubArray(vector<int>& nums) {
	return subMaxSub(0, nums.size() - 1, nums);
}

void p53::test() {
	vector<int> input{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << maxSubArray(input) << endl;
}
