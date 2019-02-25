#include"Solutions.h"
int p169::majorityElement(vector<int>& nums) {
	int n = nums.size();
	unordered_map<int, int > map;
	for (int i = 0; i < n; i++) {
		map[nums[i]]++;
		if (map[nums[i]] > n / 2) return nums[i];
	}
	return 0;
}

void p169::test() {
	vector<int> input{ 2,2,1,1,1,2,2 };
	cout << majorityElement(input) << endl;
}