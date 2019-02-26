#include"Solutions.h"

// 2D DP method
int p516::longestPalindromeSubseq_2D_DP(string s) {
	int n = s.size();
	if (n == 1) return n;
	vector<vector<int>> DP(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) DP[i][i] = 1;
	//DP method
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) { // pay attention to i loop index
			int j = i + l - 1; // ending index
			if (s[i] == s[j]) {
				DP[i][j] = 2 + DP[i + 1][j - 1];
			}
			else {
				DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]);
			}
		}
	}
	return DP[0][n - 1];
}


int p516::longestPalindromeSubseq(string s) { // dpx save length rolling
	int n = s.size();
	vector<int> dp0(n, 0); // l length
	vector<int> dp1(n, 0); // l - 1 length
	vector<int> dp2(n, 0); // l - 2 length
	// only need three type of length
	for (int l = 1; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			int j = i + l - 1;
			if (i == j) {
				dp0[i] = 1;
				continue;
			}
			if (s[i] == s[j]) {
				dp0[i] = 2 + dp2[i + 1];
			}
			else {
				dp0[i] = max(dp1[i + 1], dp1[i]);
			}
		}
		swap(dp0, dp1);
		swap(dp2, dp0);
		
	}
	return dp1[0];
}


void p516::test() {
	string s = "bbbab";
	cout << longestPalindromeSubseq(s) << endl;
}