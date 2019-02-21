#include"Solutions.h"
// reference to solution from https://www.youtube.com/watch?v=vxIMqdR8flY
// this method is smart by wondering about normal method
// could buy and sell on same day
// greedy method
int p122::maxProfit(vector<int>& prices) {
	int ans = 0;
	for (int i = 1; i < prices.size(); i++) {
		int dif = prices[i] - prices[i - 1];
		if (dif > 0) ans += dif;
	}
	return ans;
}

void p122::test() {

}