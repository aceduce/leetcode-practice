# include"Solutions.h"

//backtracking method
// with obstacle
// overflow on the DP matrix
int p63::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<unsigned long long>> DP(m, vector<unsigned long long>(n, 0));
	//DP[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
	for (size_t i = 0; i < m; i++) { // wrong initialzations!!
		//DP[i][0] = (obstacleGrid[i][0] == 1) ? 0 : 1;
		if (obstacleGrid[i][0] == 1) break;
		else DP[i][0] = 1;
	}
	for (size_t i = 0; i < n; i++) {
		if (obstacleGrid[0][i] == 1) break;
		else DP[0][i] = 1;
	}
	for (size_t i = 1; i < m; i++) {
		for (size_t j = 1; j < n; j++) {
			//DP[i][j] = ((obstacleGrid[i][j] == 1) ? 0 : (DP[i - 1][j] + DP[i][j - 1]));
			if (obstacleGrid[i][j] == 1)  continue;
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
			}
		}
	return DP[m - 1][n - 1];
	}



void p63::test() {
	vector<vector<int>> gridO{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
	cout << uniquePathsWithObstacles(gridO) << endl;
}