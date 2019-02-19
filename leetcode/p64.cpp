#include"Solutions.h"

// a typical dp problem
int p64::minPathSum(vector<vector<int>>& grid) {
	if (grid.size() == 0) return 0;
	vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
	//initializations:
	for (int i = 1; i <= grid.size(); i++) {
		dp[i][1] = dp[i - 1][1] + grid[i-1][0];
	}
	for (int i = 1; i <= grid[0].size(); i++) {
		dp[1][i] = dp[1][i - 1] + grid[0][i-1];
	}
	for (int i = 2; i <= grid.size(); i++) {
		for (int j = 2; j <= grid[0].size(); j++) {
			dp[i][j] = min(dp[i - 1][j] + grid[i - 1][j - 1], dp[i][j - 1] + grid[i - 1][j - 1]);
		}
	}
	return dp[grid.size()][grid[0].size()]; // index is always -1
}

void p64::test() {
	vector<vector<int>> input = {
		{1,3,1}, {1,5,1},{4,2,1}
	};
	cout << minPathSum(input) << endl;
}
