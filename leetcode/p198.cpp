#include "Solutions.h"
// need to do recursive calls

// TLE with recursive callss...
void subrob(vector<int> & nums, int index, int &ans, int &tmp) {
	int n = nums.size();
	if (index >= n) { // reaching the last house
		ans = (ans > tmp) ? ans : tmp;
		return;
	}
	for (int i = index; i < n; i++) {
		// rob i house
		int a = tmp;
		tmp += nums[i];
		subrob(nums, index + 2, ans, tmp); // need to skip one house though
		tmp = a; // not robbing the house
	}
}
int p198::rob_TLE(vector<int>& nums) {
	int tmp = 0, ans = 0;
	subrob(nums, 0, ans, tmp);
	return ans;
}

// has to use DP 
// steal nums[i] + DP[i-2]
// not steal nums[i-1]
int p198::rob(vector<int> & nums) {
	int n = nums.size();
	if (n == 1) return nums[0];
	if (n < 1) return 0;
	vector<int> DP(n + 1, 0);
	DP[1] = nums[0];  // DP ith val means max at house i (house seq from 1, 2, ...n)
	for (int i = 2; i <= n; i++) {
		DP[i] = max(DP[i - 1], DP[i - 2] + nums[i - 1]);
	}
	return DP[n];
}

void p198::test() {
	vector<int> input{ 1,2,3,1 };
	cout << rob(input) << endl;
}