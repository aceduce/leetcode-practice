#include"Solutions.h"


class Solution_BF {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto coin : coins) {
            for (int i = amount - coin; i >= 0; --i)
                if (dp[i] != INT_MAX)
                    for (int k = 1; k * coin + i <= amount; ++k)
                        dp[i + k * coin] = min(dp[i + k * coin], dp[i] + k);
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


class Solution_DP {
public:
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (auto const & c : coins) {
			for (int i = c; i <= amount; i++) {
				if (dp[i - c] != INT_MAX) {
					dp[i] = min(dp[i], dp[i - c] + 1);
				}
			}
		}
		return dp[amount];
	}
};

class Solution_DFS {
public:
	void subcoin_DFS(vector<int> & coins, int searchidx, int residual, int  used, int & ans) {
		if (residual == 0) {
			ans = min(ans, used);
			return;
		}
		if (searchidx == coins.size()) // reach the end already
			return;

		//for (int i = searchidx; i < coins.size(); i ++ ) {
		// DO NOT NEED AN EXTRA LOOP!
		int c = coins[searchidx];
		for (int k = residual / c; k >= 0 && ans > used + k; k--) // pruning shown here!!!!!
			subcoin_DFS(coins, searchidx + 1,residual - k * c, used + k, ans);
		//}
	}
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.rbegin(), coins.rend()); // sort the coins from high value to low values
		int ans = INT_MAX;
		subcoin_DFS(coins, 0, amount, 0, ans);
		return ans == INT_MAX ? -1 : ans;
	}
};