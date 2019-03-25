#include"Solutions.h"
// https://www.youtube.com/watch?v=SFCiuIJu17Y
// recursively calcualte this problem!
// Memorized Recursion Method
class p673::Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		c_ = vector<int>(n, 0);
		l_ = vector<int>(n, 0);

		// find the length of LIS
		int max_len = 0;
		for (int i = 0; i < n; i++) {
			max_len = max(max_len, len(nums, i));
		}
		int ans = 0; // this is count
		for (int i = 0; i < n; i++) {
			if (len(nums, i) == max_len)
				ans += count(nums, i);
		}
		return ans;
	}

private:
	vector<int> c_; // number of LIS ends with nums[i] / NLIS'
	vector<int> l_; // number of LIS ends with nums[i] / LIS'
	
	// Recursive calls with memorization
	// NLIS'
	int count(const vector<int> & nums, int n) {
		if (n == 0) return 1;
		if (c_[n] > 0) return c_[n];

		int total_count = 0;
		int l = len(nums, n); // return the LIS ending with n /LIS'
		for (int i = 0; i < n; i++) { // elist all lthe sub arrays
			if (nums[n] > nums[i] && len(nums, i) == l - 1) {
				total_count += count(nums, i);
			}
		}
		// no element i is smaller than the nth element
		if (total_count == 0) total_count = 1;
		return c_[n] = total_count;
	}
	// ge thte LIS
	// LIS'
	int len(const vector<int> & nums, int n) {
		if (n == 0) return 1;
		if (l_[n] > 0) return l_[n];
		int max_len = 1;
		// check every subarray
		for (int i = 0; i < n; ++i) {
			if (nums[n] > nums[i]) {
				max_len = max(max_len, len(nums, i) + 1);
			}
		}
		return l_[n] = max_len;
	}
};

// iteative method
class Solution_iter {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;

		vector<int> c(n, 1);
		vector<int> l(n, 1);

		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (nums[i] > nums[j]) {
					if (l[j] + 1 > l[i]) {
						l[i] = l[j] + 1;
						c[i] = c[j];
					}
					else if (l[j] + 1 == l[i]) {
						c[i] += c[j];
					}
				}

		int max_len = *max_element(l.begin(), l.end());

		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (l[i] == max_len)
				ans += c[i];

		return ans;
	}
};