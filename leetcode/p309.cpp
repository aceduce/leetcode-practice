#include"Solutions.h"
// inspired by HuaHua's video on youtube
int p309::maxProfit(vector<int>& prices) {
	int ans = 0;
	int hold = INT_MIN, sold = 0, rest = 0;
	for (int i = 0; i < prices.size(); i++) {
		int tmp = hold; // hold the t-1 value
		hold = max(hold, rest - prices[i]);
		rest = max(rest, sold);
		sold = tmp + prices[i];
	}
	ans = max(sold, rest);
	return ans;
}

void p309::test() {
	
}