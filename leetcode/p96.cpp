#include "Solutions.h"
//using the DP: each n nodes BST has root 1 --> n
int p96::numTrees(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1; 
	if (n < 2) return dp[n];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i - 1; j++){
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	return dp[n];
}

void p96::test() {
	cout << numTrees(3) << endl;
}