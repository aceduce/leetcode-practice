#include"Solutions.h"
// Binary search method
int p153::findMin(vector<int>& nums) {
	// need to have a section to deal with normal sequence
	if (nums.size() == 1) return nums[0];
	int begin = 0, end = nums.size() - 1;
	if (nums[begin] < nums[end]) return nums[0];
	while (begin < end - 1) {
		int mid = begin + (end - begin) / 2;
		if (nums[mid] > nums[begin])
			begin = mid;
		else if (nums[mid] < nums[begin])
			end = mid;
	}
	if (nums[begin] > nums[end]) return nums[end];
	else return nums[begin];
}

void p153::test() {
	vector<int> num{ 1, 2, 3 };
	cout << findMin(num) << endl;
}