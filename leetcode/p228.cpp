#include"Solutions.h"
vector<string> p228::summaryRanges(vector<int>& nums) {
	if (nums.size() == 0)
		return {};
	vector<string> ans;
	int left = 0, right = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		int left_val = nums[i];
		int right_val;
		int j = i;
		while (j + 1 < n && (long long)nums[j + 1] - (long long)nums[j] == 1) { // continous
			j++;
		}
		if (j == i) { // not continous
			ans.push_back(to_string(left_val));
		}
		else {
			right_val = nums[j];
			i = j;
			ans.push_back((to_string(left_val) + "->" + to_string(right_val)));
		}

	}
	return ans;
}