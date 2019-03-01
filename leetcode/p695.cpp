#include"Solutions.h"
int p695::DFS(vector<vector<int>>& grid, int x, int y) {
	int n = grid.size();
	if (n == 0) return 0;
	int m = grid[0].size();
	int ans = 0;
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
	grid[x][y] = 0; // switch from 1-> 0
	ans++;
	int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
	for (int k = 0; k < 4; k++) {
		ans = ans + DFS(grid, x + dx[k], y + dy[k]);
	}
	return ans;
}

int p695::maxAreaOfIsland(vector<vector<int>>& grid) {
	int n = grid.size();
	if (n == 0) return 0;
	int m = grid[0].size();
	int ans = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1)
				ans = max(ans, DFS(grid, i, j));
		}
	return ans;
}

void p695::test() {
	vector<vector<int>> grid{ {0,0,1,0,0,0,0,1,0,0,0,0,0},
							 {0,0,0,0,0,0,0,1,1,1,0,0,0},
							 {0,1,1,0,1,0,0,0,0,0,0,0,0},
							 {0,1,0,0,1,1,0,0,1,0,1,0,0},
							 {0,1,0,0,1,1,0,0,1,1,1,0,0},
							 {0,0,0,0,0,0,0,0,0,0,1,0,0},
							 {0,0,0,0,0,0,0,1,1,1,0,0,0},
							 {0,0,0,0,0,0,0,1,1,0,0,0,0} };
	cout << maxAreaOfIsland(grid) << endl;
}