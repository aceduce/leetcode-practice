#include"Solutions.h"
class p718::Solution_DP {
public:
	// Sub-string is continous
	// DP[i][j] = 
	// a. A[i] == B[j] : DP[i-1][j-1] + 1
	// b. A[i] != B[j] : 0
	int findLength(vector<int>& A, vector<int>& B) {
		int m = A.size();
		int n = B.size();
		int ans = 0;
		vector<vector<int>>DP(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (A[i - 1] == B[j - 1]) {
					DP[i][j] = DP[i - 1][j - 1] + 1;
					if (ans < DP[i][j]) ans = DP[i][j];
				}
				else DP[i][j] = 0;
			}
		}
		return ans;
	}
};