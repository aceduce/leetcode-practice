#include"Solutions.h"

// seem to be a typical DP problem
int p120::minimumTotal(vector<vector<int>>& triangle) {
	int v = triangle.size();
	int h = triangle[v-1].size();
	vector <vector<int>> DP(v, vector<int>(h, 0));

	// initilizations
	// think along the same direction as known triangle

	DP[0][0] = triangle[0][0];
	// spend half an hour on initilaization wrongs...
	for (int i = 1; i < v; i++) {
		DP[i][0] = triangle[i][0] + DP[i-1][0];
		DP[i][i] = triangle[i][i] + DP[i-1][i-1];
	}
	for (int i = 2; i < v; i++) {
		for (int j = 1; j <= i - 1; j++) {
			int tmp = (j >= i) ? 0 : DP[i - 1][j];
			DP[i][j] = min(tmp, DP[i - 1][j - 1]) + triangle[i][j];
		}
	}
	/*
	int ans = INT_MAX;
	for (int i = 0; i < h; i++) {
	ans = (ans < DP[v - 1][i]) ? ans : DP[v - 1][i];
	}
	*/

	// use sort to replace above
	sort(DP[v - 1].begin(), DP[v - 1].end()); // ues end is much faster, but +h is also correct!
	return DP[v - 1][0];
}

void p120::test() {
	vector<vector<int>> input{
		{2}, {3,4}, {6,5,7},{4,1,8,3} };
	cout << minimumTotal(input) << endl;
}