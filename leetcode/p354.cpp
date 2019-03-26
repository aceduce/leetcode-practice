#include"Solutions.h"
// extends the longest increasing sequence method 
// (Extends to 2D)	
class p354::Solution_BF_wDP {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int size = envelopes.size();
		// can skip hte lambda function, like following:
		// sort(envelopes.begin(), envelopes.end());
		//
		sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int> &b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		});
		vector<int> dp(size, 1);
		int ans = 1;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
				ans = max(ans, dp[i]);
			}
		}
		return ans;
	}
};

class p354::Solution_wBST {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int size = envelopes.size();
		// sorting is very triky
		sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int> &b) {
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
		});
		vector<int> dp;
		int ans = 1;
		for (auto const & e : envelopes) {
			auto it = lower_bound(dp.begin(), dp.end(), e.second);
			if (it == dp.end())
				dp.push_back(e.second);
			else *it = e.second;
		}
		return dp.size();
	}
};