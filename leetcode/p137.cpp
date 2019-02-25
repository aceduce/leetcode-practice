#include"Solutions.h"
// use bits opers
// not very popular, from facebook
// https://www.youtube.com/watch?v=puXcQpwgcD0
int p137::singleNumber_mode(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	int res = 0;
	for (int i = 0; i < 32; i++) {
		int sum = 0;
		for (int num : nums) {
			sum += (num >> i) & 1; // which pos to extract!
			sum %= 3; // only handling ith postion
		}
		res = res | (sum << i); // | is just like attachment
	}
	return res;
}

int p137::singleNumber(vector<int> &nums) {
	int ones = 0, twos = 0;
	for (int i = 0; i < nums.size(); i++) {
		ones = (ones ^ nums[i]) & ~twos;
		twos = (twos ^ nums[i]) & ~ones;
	}
	return ones;
}


void p137::test() {
	vector<int> a = { 2, 2, 3, 2 };
	cout<<singleNumber(a) << endl;
}