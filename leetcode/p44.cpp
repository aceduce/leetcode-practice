#include"Solutions.h"
bool p44::isMatch(string s, string p) {
	int s_size = s.size();
	int p_size = p.size();
	if (s_size == 0 && p_size == 0) return true;
	//if (s_size == 0 || p_size == 0) return false;
	vector<vector<bool>> dp(s_size + 1,  vector<bool>(p_size + 1, false));
	dp[0][0] = true;
	// or to use fn = fn-1
	for (int i = 0; i < p_size; i++) {
		while (p[i] == '*' && i < p_size) { // continuous stars then true;
			dp[0][i + 1] = true; // need to make sure there's + 1
			i++;
		}
		break;
	}

	for (int i = 1; i <= p_size; i++) {
		for (int j = 1; j <= s_size; j++) {
			dp[j][i] = (((p[i - 1] == '?') && dp[j - 1][i - 1]) || // p has a ?
				(s[j - 1] == p[i - 1] && dp[j - 1][i - 1])) ||  // chars matches btw p and s
				((p[i - 1] == '*') && (dp[j][i - 1] || dp[j - 1][i]));              // no char or any char: put one char here
			// any char actually comes from left...
		}
	}
	return dp[s_size][p_size];
}

void p44::test() {
	string s = "", p = "a";
	cout << isMatch(s, p) << endl;
}