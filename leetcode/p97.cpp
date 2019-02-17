#include"Solutions.h"
// conceptuall difficult DP
// s1 vertial; s2 horizontal

bool p97::isInterleave(string s1, string s2, string s3) {
	int l1 = s1.size();
	int l2 = s2.size();
	int l3 = s3.size();
	//if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0) return false;
	if (l1 + l2 != l3) return false;
	// dim: l1 + 1 x dim: l2 + 1
	vector<vector<bool>>DP (l1 +1, vector<bool>(l2 + 1, false));
	DP[0][0] = true;
	// this is index corresponding to the string #3
	// pay attention to the boundaries: s1, s2 span through the true sizes (that's why they has size - 1 in index
	// s3 goes with index
	for (int i = 0; i < l1 + l2; i++) {
		for (int s1_len = 0; s1_len <= l1 && s1_len <= i + 1; s1_len++) { // s1 refers to true length
			int s2_len = i + 1 - s1_len; // starting with 0, i + 1 is the s3 length

			if (s2_len > l2) continue; // skip this, s3 too long

			if ((s1_len > 0 && s1[s1_len - 1] == s3[i] && DP[s1_len - 1][s2_len]) ||  // vertical path
				s2_len > 0 && s2[s2_len - 1] == s3[i] && DP[s1_len][s2_len -1]) // horizontal
				DP[s1_len][s2_len] = true;
		}
	}
	return DP[l1][l2];
}

void p97::test() {
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout << isInterleave(s1, s2, s3) << endl;
}