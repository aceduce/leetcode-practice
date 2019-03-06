#include"Solutions.h"
int p174::calculateMinimumHP(vector<vector<int>>& dungeon) {
	// should be alive at any point, not just ending...
		// bottom up method
		int n = dungeon.size();
		int m = dungeon[0].size();
		vector<vector<int>> ans(n, vector<int>(m, 0));
		// reverse finally
		ans[n - 1][m - 1] = (dungeon[n - 1][m - 1] <= 0) ? 1 - dungeon[n - 1][m - 1] : 1;
		for (int i = n - 1; i > 0; i--) {
			ans[i - 1][m - 1] = ans[i][m - 1] - dungeon[i - 1][m - 1];
			ans[i - 1][m - 1] = (ans[i - 1][m - 1] <= 0) ? 1 : ans[i - 1][m - 1];
		}
		for (int i = m - 1; i > 0; i--) {
			ans[n - 1][i - 1] = ans[n - 1][i] - dungeon[n - 1][i - 1];
			ans[n - 1][i - 1] = (ans[n - 1][i - 1] <= 0) ? 1 : ans[n - 1][i - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = m - 2; j >= 0; j--) {
				ans[i][j] = -dungeon[i][j] + min(ans[i + 1][j], ans[i][j + 1]);
				ans[i][j] = ans[i][j] <= 0 ? 1 : ans[i][j];
			}
		}
		return ans[0][0];
	}

void p174::test() {

}