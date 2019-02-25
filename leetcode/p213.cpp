#include"Solutions.h"

// inspired by Basket
int p213::rob(vector<int>& nums) {
	// use a duo-channel
	int n = nums.size();
	vector<int> rf_no_rob(n, 0);
	vector<int> rf_rob(n, 0);
	vector<int> no_rf_no_rob(n, 0);
	vector<int> no_rf_rob(n, 0);
	rf_rob[0] = nums[0];
	no_rf_no_rob[0] = nums[0];

	for (int i = 1; i < n; i++) {
		rf_rob[i] = rf_no_rob[i - 1] + nums[i];
		rf_no_rob[i] = max(rf_rob[i - 1], rf_no_rob[i - 1]);
		no_rf_rob[i] = no_rf_rob[i - 1] + nums[i];
		no_rf_no_rob[i] = max(no_rf_no_rob[i - 1], no_rf_rob[i - 1]);
	}

	return 0;
}

void p213::test() {

}