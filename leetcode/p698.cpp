#include"Solutions.h"
class p698::Solution {
	// Brutal force method with DFS
	// with two optimizations involved
public:
	bool sub_dfs(vector<int> & nums, vector<int> & groups, int row, int & target) {
		if (row < 0) return true;
		int val = nums[row--]; // value to accomendate
		int size = groups.size();
		for (int i = 0; i < size; i++) {
			if (groups[i] == target) continue;
			// this is a typical combination case
			if (groups[i] + val <= target) {
				groups[i] += val;
				if (sub_dfs(nums, groups, row, target)) return true;
				groups[i] -= val;
			}
			if (groups[i] == 0) break; // make sure the first group has zero filled up before filling later groups
		}
		return false;
	}
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum%k != 0) return false;
		sort(nums.begin(), nums.end());
		int row = nums.size() - 1;
		int target = sum / k;
		if (nums.back() > target) return false;
		while (row >= 0 && nums[row] == target) {
			row--;
			k--; // reduce one group
		}
		// number of groups to fill-in
		vector<int> groups(k);
		return sub_dfs(nums, groups, row, target);
	}
};

class p698::Solution_DP_memo {
	// DP with top-down memorization
public:
	enum Result { GOOD, BAD, INIT }; // -1 : initizlized
	bool search(int used, int todo, vector<Result> & memo, vector<int> &nums, int & target) {
		if (memo[used] == INIT) {
			memo[used] = Result{ BAD }; // not valid result
			int targ = (todo - 1) % target + 1;
			for (int i = 0; i < nums.size(); i++) {
				if ((((used >> i) & 1) == 0) && nums[i] <= targ) {
					if (search(used | (1 << i), todo - nums[i], memo, nums, target)) {
						memo[used] = Result{ GOOD };
						break; // find the result for using all these elements
					}
				}
			}
		}
		return memo[used] == Result{ GOOD };
	}

	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k > 0) return false;

		vector<Result> memo(1 << nums.size(), INIT);
		memo[(1 << nums.size()) - 1] = Result{ GOOD };
		int target = sum / k;
		bool res = search(0, sum, memo, nums, target);
		return res;
	}
};
