#include"Solutions.h"
int p91::numDecodings(string s) {
	int len = s.size();
	vector<int> dp(len + 1, false);
	dp[0] = 1;
	for (int i = 1; i <= len; i++) {
		int num = stoi(s.substr(i - 1, 1)); // one digits
		if (num > 0 && num < 10) dp[i] += dp[i - 1];
		if (i >= 2 && stoi(s.substr(i - 2, 2)) > 0 && stoi(s.substr(i - 2, 2)) < 27 && s[i-2]!='0') dp[i] += dp[i - 2];
	}
	return dp[len];
}

void p91::test() {
	cout << numDecodings("01") << endl;
}