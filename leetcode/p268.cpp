#include"Solutions.h"
int p268::missingNumber(vector<int>& nums) {
	int n = nums.size();
	vector<bool> map(n + 1, false);
	for (int i = 0; i < n; i++) {
		map[nums[i]] = true;
	}
	for (int i = 0; i < n + 1; i++) {
		if (!map[i]) return i;
	}
	return 0;
}

void p268::test() {

}