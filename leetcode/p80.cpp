#include"Solutions.h"

// clear thoughts:
// double pointer, didn't solve by myself...
// need to move any way
// location pointer vs flaoting pointer!!!
int p80::removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 2) return nums.size();
	int loc = 2;
	for (int i = 2; i < nums.size(); i++) {
		if (nums[loc - 1] == nums[loc - 2] && nums[i] == nums[loc - 2]) continue;
		else {
			nums[loc] = nums[i];
			loc++;
		}
	}
	return loc;
}

void p80::test() {
	vector<int> input{ 1 };
	int ans = removeDuplicates(input);
	cout << ans<< endl;
	for (int i = 0; i <= ans -1; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
}