#include"Solutions.h"
int p70::climbStairs(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

void p70::test() {
	cout << climbStairs(3) << endl;
}