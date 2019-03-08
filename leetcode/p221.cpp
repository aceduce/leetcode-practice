#include"Solutions.h"
// Two methods:
// https://www.youtube.com/watch?v=vkFUB--OYy0
// 1. DP (more general method
// 2. Accelerated DP

// Method # 1:
	 // pre-compute with DP method!
	 // enumerate all the top-left corners
	 // then compute the whole size 
	 // more Univerals
int p221::maximalSquare_DP_Gen(vector<vector<char>>& matrix) {
	int n = matrix.size();
	if (n == 0) return 0;
	int m = matrix[0].size();
	if (m == 0) return 0;
	vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
	// Create a accumulated (0,0) to (x, y) look up:
	// x correspond to col; y correspond to rows (y, x)
	for (int i = 1; i <= n; i++) { // row = y (i)
		for (int j = 1; j <= m; j++) { // col = x (j)
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] -
				DP[i - 1][j - 1]
				+ matrix[i - 1][j - 1] - '0'; // mapping is DP[1][1] --> matrix[0][0];  i.e. DP[i][j]: 0 to matrix [i - 1][j -1]
		}
	}
	// answer fill
	// understand the subscripts such as -1 
	int ans = 0;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) { // correponding to: when x = 1, size is m
			// consider the size: Range[x, x + size - 1]
			for (int size = min(m - x + 1, n - y + 1); size >= 1; size--) {
				// min is to obtain the size, also from big to small, such that the loop can finish up early
				// starting from (x, y) to different sizes, from large to small
				int area = DP[y + size - 1][x + size - 1] + DP[y - 1][x - 1]
					- DP[y + size - 1][x - 1] - DP[y - 1][x + size - 1];
				if (area == size * size) {
					ans = max(ans, area);
					break; // break from the area, as area SHRINK SHRINK!
				}
			}

		}
	}
	return ans;
}

// Method # 2:
// Method # 2: USE DP
	 // DP(i, j) = min[ DP(i - 1, j), DP(i, j - 1), DP(i - 1, j -1)]
	 // DP(i, j) means the square size with (i,j) as the bottom right!
int p221::maximalSquare(vector<vector<char>>& matrix) {
		int n = matrix.size();
		if (n == 0) return 0;
		int m = matrix[0].size();
		int ans = 0;
		vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (matrix[i - 1][j - 1] == '1') {
					DP[i][j] = min(min(DP[i][j - 1], DP[i - 1][j]), DP[i - 1][j - 1]) + 1;
				}
				else {
					DP[i][j] = 0;
				}
				ans = max(ans, DP[i][j]);
			}
		}
		return ans * ans;// ans is just edge
	}



void p221::test() {

}