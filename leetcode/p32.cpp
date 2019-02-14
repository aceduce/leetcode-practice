# include "Solutions.h"	

int Solutions::p32::longestValidParentheses(string s) {
	int n = s.size();
	int ans = 0;
	vector<int> dp(n, 0); // initalizat to all zeros
	for (int i = 0; i < n; i++) {
		if (i > 0 && (s[i] == ')' && s[i - 1] == '(')) { // first elem is zero
			if (i >= 2) dp[i] = dp[i - 2] + 2;
			else { // when i = 1, the first pair
				dp[i] = 2;
			} 
		}
		else if(i > 1 && s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i -1]-1] == '('){
			if (i - dp[i - 1] - 1 == 0 ) {
				dp[i] = 2 + dp[i - 1];
			} else dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
		}
		ans = (dp[i] > ans) ? dp[i] : ans;
	}
	return ans;
}

//"(()())"