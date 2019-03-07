#include"Solutions.h"

// turn out we can do O(n), only care about a window of k
bool p219::containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_set<int> set;
	for (int i = 0; i < nums.size(); i++) {
		if (i > k)
			set.erase(nums[i - k - 1]);
		if (set.count(nums[i])) return true;
		set.insert(nums[i]);
	}
	return false;
}

// O(N^2) solution
bool p219::containsNearbyDuplicate_slow(vector<int>& nums, int k) {
	unordered_map<int, vector<int>> map;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]].push_back(i);
	}
	for (const auto & num : map) {
		if (map[num.first].size() > 1) {
			//map.erase(num.first);
			//sort(map[num.first].begin(), map[num.first].end());
			for (int i = 1; i < map[num.first].size(); i++) {
				if (map[num.first][i] - map[num.first][i - 1] <= k)
					return true;
			}
		}
	}
	return false;
}