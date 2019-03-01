#include"Solutions.h"
// no need to use DFS
// just traverse..
// two methods:
// find the two borders: http://www.cnblogs.com/grandyang/p/6096138.html
// or look at up/left (choose second method)
int p463::islandPerimeter(vector<vector<int>>& grid) {
	int n = grid.size();
	if (n == 0) return 0;
	int m = grid[0].size();
	int ans = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				ans += 4;
				if (i > 0 && grid[i - 1][j] == 1)  ans -= 2;
				if (j > 0 && grid[i][j - 1] == 1) ans -= 2;
				/* alternative is:
				if(j == 0 || [i][j] == 0) res++ // a true left border
				*/
			}
		}
	return ans;
}

void p463::test() {

}