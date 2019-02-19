#include"Solutions.h"

// very smark DP method!!!
// need to get the insight:
// row is the manipulation string
// insert: (i, j) --> (i, j -1) + 1
// replace: (i, j) --> (i - 1, j -1) + 1
// delete: (i, j) --> (i-1, j) + 1

int p72::minDistance(string word1, string word2) {
	int len1 = word1.size();
	int len2 = word2.size();
	vector<vector<int>> DP(len1 + 1, vector<int>(len2 + 1, INT_MAX)); // must initialize to a really high value!
	for (int i = 0; i <= len1; i++) {
		DP[i][0] = i;
	}
	for (int i = 0; i <= len2; i++) {
		DP[0][i] = i;
	}
	//int ans = INT_MAX;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				DP[i][j] = min(min(DP[i - 1][j - 1], DP[i - 1][j] + 1), DP[i][j - 1] + 1);
			}
			else {
				DP[i][j] = min(min(DP[i - 1][j - 1] + 1, DP[i - 1][j] + 1), DP[i][j - 1] + 1);
			}
		}
	}
	return DP[len1][len2];
}

void p72::test() {
	string w1 = "horse";
	string w2 = "ros";
	cout << minDistance(w1, w2) << endl;
}