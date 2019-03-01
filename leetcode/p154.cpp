#include"Solutions.h"
// time complexity :; O(n) as duplicates shows, T(n) = 2*T(n/2)
int p154::findMin(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	int st = 0, end = nums.size() - 1;
	while (st < end - 1) {
		int mid = st + (end - st) / 2;
		// every time, need to put a normal sequence check
		if (nums[st] < nums[end]) return nums[st]; // must be strictly sorted!!! Using < not <=
		if (nums[mid] < nums[st])
			end = mid;
		else if (nums[mid] > nums[st])
			st = mid;
		else st++;
	}
	if (nums[st] < nums[end]) return nums[st];
	else return nums[end];
}

void p154::test() {

}