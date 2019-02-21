#include"Solutions.h"

// use State machine method
int p714::maxProfit(vector<int>& prices, int fee) {
	if (prices.size() <= 1) return 0;
	int sold = 0;
	int hold = INT_MIN/2; // has to cut by half to prevent overflw
	for (int i = 0; i < prices.size(); i++) {
		sold = max(sold, hold + prices[i] - fee);
		hold = max(hold, sold - prices[i]);
	}
		return sold;
}

// alternative is list out the first state and run the loop from 1st
// 

void p714::test() {

}