#include"Solutions.h"

// with pointers
int p209::minSubArrayLen(int s, vector<int>& nums) {
	int left = 0;
	int ans = INT_MAX;
	int sum = 0;
	for (int right = 0; right < nums.size(); right++) {
		sum += nums[right];
		while (sum >= s && left <= right) {
			ans = min(ans, right - left + 1);
			sum -= nums[left++];
		}
	}
	return ans == INT_MAX ? 0 : ans;
}



class p209::Solution_BST {
public:
	// using BST
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		vector<int> sums(n + 1, 0);
		// sums_i mean the sum up to (inclusive) ith element
		for (int i = 1; i <= n; i++)
			sums[i] = sums[i - 1] + nums[i - 1];
		int ans = INT_MAX;
		// use the lower_bound method implementated with BST
		for (int i = 1; i <= n; i++) { // at least one element
			int sum_find = sums[i - 1] + s;
			auto bound = lower_bound(sums.begin(), sums.end(), sum_find);
			if (bound != sums.end()) { // a value found
				ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};

void p209::test() {

}