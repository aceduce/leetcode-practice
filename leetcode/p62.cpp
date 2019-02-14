#include"Solutions.h"

// my attempt at DP
int p62::uniquePaths(int m, int n) {
	vector<vector<int>> DP(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) DP[i][0] = 1;
	for (int j = 0; j < n; j++) DP[0][j] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}
	return DP[m - 1][n - 1];
}

void p62::test() {
	cout << uniquePaths(7, 3) << endl;
}