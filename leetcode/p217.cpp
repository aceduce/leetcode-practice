#include"Solutions.h"
bool p217::containsDuplicate(vector<int>& nums) {
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.count(nums[i]))
			return false;
		map[nums[i]]++;
	}
	return true;
}