#include"Solutions.h"
// should have used keep mins
// so that it could be an O(n)
int p121::maxProfit_slow(vector<int>& prices) {
	if (prices.size() == 0) return 0;
	// use for loop, a bit like a DP
	vector<int> DP(prices.size(), 0);
	int m = INT_MAX;
	for (int i = 1; i < prices.size(); i++) {
		for (int j = 0; j < i; j++) {
			m = (m < prices[j]) ? m : prices[j];
		}
		DP[i] = prices[i] - m;
	}
	sort(DP.begin() + 1, DP.end());
	return (DP[prices.size() - 1] > 0) ? DP[prices.size() - 1] : 0;
}

// one pass answer
int p121::maxProfit(vector<int>& prices) {
	int minprice = INT_MAX;
	int maxprofit = 0;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < minprice)
			minprice = prices[i]; // tricky, since one day just do onething is okay
		else if (prices[i] - minprice > maxprofit)
			maxprofit = prices[i] - minprice;
	}
	return maxprofit;
}

void p121::test() {
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << maxProfit(prices) << endl;
}