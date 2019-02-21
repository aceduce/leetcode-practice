#include"Solutions.h"

// Use left and right loop to do the calculation
// 1. left find the min price, take subtraction to obtain the maxprofit (keep max)
// 2 .right find the max price, take subtracktion to find the maxprofit
// 3. calculat the summations
int p123::maxProfit_twoloops(vector<int>& prices) {
	if (prices.size() < 1) return 0;
	int ans = 0;
	int size = prices.size();
	vector<int>profit_tran1(size, 0);
	vector<int>profit_tran2(size, 0);
	int minprice = INT_MAX;
	int maxprice = INT_MIN;
	int maxprofit = INT_MIN;
	// sort the summation and find the max value
	for (int i = 0; i < size; i++) { // one - loop effort
		if (prices[i] < minprice) {
			minprice = prices[i];
		}
		maxprofit = (maxprofit > (prices[i] - minprice)) ? maxprofit : (prices[i] - minprice);
		// mistake # 1:
		//profit_tran1.push_back(maxprofit);// should not use push back!!!  it extends the array!!
		profit_tran1[i] = maxprofit;
	}
	maxprofit = INT_MIN;
	for (int i = size - 1; i >= 0; i--) {
		if (maxprice < prices[i]) {
			maxprice = prices[i];
		}
		maxprofit = (maxprofit > (maxprice - prices[i])) ? maxprofit : (maxprice - prices[i]);
		//profit_tran2.push_back(maxprofit + profit_tran1[i]);
		profit_tran2[i] = maxprofit + profit_tran1[i]; // mistake # 2, forget to add
	}
	sort(profit_tran2.begin(), profit_tran2.end());
	ans = profit_tran2.back();
	return ans;
}


void p123::test() {
	vector<int> input{ 3,3,5,0,0,3,1,4 };
	p188 prob188;
	cout << "DP method: "<<prob188.maxProfit(2, input)<< endl; // DP method
	cout << "Two loops method " <<maxProfit_twoloops(input) << endl;
}