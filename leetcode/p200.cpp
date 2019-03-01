
#include"Solutions.h"

void p200::DFS(vector<vector<char>>& grid, int x, int y) {
	int n = grid.size();
	if (n == 0) return;
	int m = grid[0].size();
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0') return; // no need to mark
	grid[x][y] = '0';
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { -1, 1, 0, 0 };
	for (int i = 0; i < 4; i++) {
		DFS(grid, x + dx[i], y + dy[i]);
	}
}


int p200::numIslands(vector<vector<char>>& grid) {
	int n = grid.size();
	if (n == 0) return 0;
	int m = grid[0].size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '1') {
				DFS(grid, i, j);
				ans++;
			}
		}
	}
	return ans;
}


void p200::test() {
	vector<vector<char>> grid{ {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
	cout << numIslands(grid) << endl;
}