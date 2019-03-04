#include"Solutions.h"
// O(n) time, O(n) linear
// could be further simplify into checking i and i + 1
// if i + 1 < i then return i 
int p162::findPeakElement_linear_scan(vector<int>& nums) {
	int size = nums.size();
	vector<bool> vec(size, false);
	if (nums[0] > nums[1]) vec[0] = true;
	if (nums[size - 1] > nums[size - 2]) vec[size - 1] = true;
	for (int i = 0; i < size - 1; i++) {
		if (nums[i + 1] > nums[i]) vec[i + 1] = true;
	}
	for (int i = size - 1; i >= 1; i--) {
		if (nums[i - 1] > nums[i]) vec[i - 1] = vec[i - 1];
		else vec[i - 1] = false;
	}
	int indx = 0;
	for (int i = 0; i < size; i++) {
		if (vec[i]) {
			indx = i;
			break;
		}
	}
	return indx;
}

int p162::subfind(vector<int>& nums, int l, int r) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (nums[mid] < nums[mid + 1])
		return subfind(nums, mid + 1, r);
	else return subfind(nums, l, mid);
}
int p162::findPeakElement(vector<int> &nums) {
	return subfind(nums, 0, nums.size() - 1);
}

void p162::test() {
	vector<int> input{ 1, 2, 3, 1 };
	cout << findPeakElement(input) << endl;
}