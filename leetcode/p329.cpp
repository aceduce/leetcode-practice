#include"Solutions.h"
// top-down DFS memorization
// DFS +  Memorization

// need to declare the private variable for this case
int p329::DFS_w_mem(const vector<vector<int>> & matrix, int x, int y) {
	int n = matrix.size();
	if (n == 0) return 0;
	//int ans = 0;
	int m = matrix[0].size();
	if (DP[x][y] != -1) return DP[x][y];
	// define neighhbors
	static int move[] = { 0, -1, 0, 1, 0, };
	DP[x][y] = 1; // minimum 'maxpath'
	for (int i = 0; i < 4; i++) {
		int nx = x + move[i];
		int ny = y + move[i + 1];
		// pay attention to the order here
		if (nx >= 0 && nx < n && ny < m && ny >= 0 && matrix[x][y] > matrix[nx][ny]) {
			DP[x][y] = max(1 + DFS_w_mem(matrix, nx, ny), DP[x][y]);
		}
	}
	return DP[x][y];
}

int p329::longestIncreasingPath(vector<vector<int>>& matrix) {
	int n = matrix.size();
	if (n == 0) return 0;
	int ans = 0;
	int m = matrix[0].size(); 
	DP = vector<vector<int>> (n, vector<int>(m, -1)); // -1 labels not calculated yet, useful for memorizations!
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, DFS_w_mem(matrix, i, j));
		}
	}
	return ans;
}

int p329::longestIncreasingPath_DFS_bottom(vector<vector<int>>& matrix) {

}


void p329::test() {
	vector<vector<int>> input = { {9,9,4},  {6,6,8},  {2,1,1} };
	cout << longestIncreasingPath_DFS_bottom(input) << endl;
}