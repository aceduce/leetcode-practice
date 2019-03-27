#include"Solutions.h"
class p746::Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int size = cost.size();
		if (size == 0) return 0;
		vector<int> dp(size + 1, 0);
		// start from either cost[0] or cost[1]
		dp[0] = cost[0];
		dp[1] = cost[1];
		// needs to reach to the top
		for (int i = 2; i <= size; i++) {
			if (i < size) {
				dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
			}
			else {
				dp[i] = min(dp[i - 1], dp[i - 2]); // at top already
			}
			
		}
		return dp[size];
	}
};

// Reduce the space Complexity

class Solution {
public:
	int minCostClimbingStairs(vector<int> & cost) {
		int f1 = 0, f2 = 0;
		for (int i = cost.size() - 1; i >= 0; --i) {
			int f0 = cost[i] + min(f1, f2);
			f2 = f1;
			f1 = f0;
		}
		return min(f1, f2);
	}
};