#include"Solutions.h"
// two sum: O(n) compelxity
vector<int> p167::twoSum(vector<int>& numbers, int target) {
	//vector<int> ans;
	// regular two sum use hashmap
	for (int l = 0, r = numbers.size(); l <= r; l++) {
		while(l < r) {
			long long a = numbers[l], b = numbers[r];
			if (a + b <= target) // right side cannot move futher
				break;
			r--;
		}
		long long a = numbers[l], b = numbers[r];
		if (a + b == target) return { l + 1, r + 1 };
	}
	return {};
}

void p167::test() {

}