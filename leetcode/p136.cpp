#include"Solutions.h"
int p136::singleNumber(vector<int>& nums) {
	//unordered_set<int> s; // cannot use set
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.count(nums[i])) 
			map.erase(nums[i]);
		else map[nums[i]]++;
	}
	return map.begin()->first;
}

