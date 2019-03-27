#include"Solutions.h"
class p664::Solution {
public:
	int turn(const string & s, int i, int j) { // print from index: i to index: j
		if (i > j) return 0;
		if (DP[i][j] > 0) return DP[i][j];
		// worst case
		int ans = turn(s, i, j - 1) + 1;
		// splitting
		for (int k = i; k < j; k++) {
			if (s[k] == s[j])
				ans = min(ans, turn(s, k + 1, j - 1) + turn(s, i, k));
		}
		// remember to put top-down TP memorization !
		return DP[i][j] = ans;
	}
	int strangePrinter(string s) {
		int m = s.size();
		if (m == 0) return 0;
		DP = vector<vector<int>>(m, vector<int>(m, 0));
		int ans = turn(s, 0, m - 1);
		return ans;
	}
private:
	vector<vector<int>> DP;
};