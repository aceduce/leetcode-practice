#include"Solutions.h"
// DP truth table + O(n^2) traverse


int p132::minCut(string s) {
	int n = s.size();
	if (n == 1) return 0;
	vector<vector<bool>> DP(n, vector<bool>(n, false));
	// initilaization for length of 1 and 2
	for (int i = 0; i < n -1; i++) {
		DP[i][i] = true;
		DP[i][i + 1] = (s[i] ==s[ i + 1 ]);
	}
	DP[n - 1][n - 1] = true;

	// length of 3 and beyond:
	for (int len = 3; len <= n; len++) {  // important to have len = n
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;  // ending index for len 
			if (s[i] == s[j] && (DP[i + 1][j - 1])) {
				DP[i][j] = true;
			}
		}
	}
	// DP mask done
	// optmized method with space O(n), time O(n^2)
	vector<int> ansVec(n, 0);
	for (int i = 1; i < n; i++) {
		int tmp = INT_MAX;
		if (DP[0][i]) { 
			ansVec[i] = 0;
			continue;
		}
		for (int j = 0; j < i; j++) { // j loop from zero to i - 1, sep into [0, j] [j+1, i]

			if (DP[j+1][i] && (tmp > (ansVec[j] + 1)) ) {
				tmp = ansVec[j] + 1;
			}
		}
		ansVec[i] = tmp;
	}
	return ansVec[n - 1];
}

// less- optimized method: DP value table --> NEED isPan function
bool p132::isPan(string s, int st, int end) {
	while (st < end) {
		if (s[st++] != s[end--]) return false;
	}
	return true;
}

//https://www.youtube.com/watch?v=lDYIvtBVmgo
int p132::minCut_lessopt(string s) {
	int n = s.size();
	vector<vector<int>> ansVec(n, vector<int>(n, 0));
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) ansVec[i - 1][i] = 1; // for two different characters, need one cut!
	}
	// DP loop
	for (int l = 3; l <=n; l++) {
		for (int i = 0; i <= n - l; i++) {
			int tmp = INT_MAX;
			int j = i + l - 1;
			if (isPan(s, i, j)) ansVec[i][j] = 0;
			else {
				for (int m = i; m < j; m++) {
					// sep into [i, m] [m + 1, j]
					if (tmp > (ansVec[i][m] + ansVec[m + 1][j] + 1)) {
						tmp = ansVec[i][m] + ansVec[m + 1][j] + 1;
					}
				}
				ansVec[i][j] = tmp;
			}
		}
	}
	return ansVec[0][n - 1];
}

void p132::test() {
	string s = "aab";
	cout << minCut(s) << endl;
	cout << minCut_lessopt(s) << endl;
}