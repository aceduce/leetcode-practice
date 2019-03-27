#include"Solutions.h"
// O(Nlog) method
class p324::Solution {
public:
	void wiggleSort(vector<int>& nums) {
		// use sort first section and second section
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		int mid = (nums.size() - 1) / 2;
		int end = nums.size() - 1;
		for (int i = 0; i < nums.size(); i++) {
			nums[i] = (i & 1) ? tmp[mid--] : tmp[end--];
		}
		return;
	}
};