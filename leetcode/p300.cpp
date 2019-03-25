#include"Solutions.h"
// this is an easier/sub version of P673!
class Solution_recursive {
public:
	int lengthOfLIS(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) return 0;
		int max_len = 1;
		l_ = vector<int>(size, 0);
		// here, I use recursive call method
		for (int i = 0; i < size; i++) {
			max_len = max(max_len, len(nums, i));
		}
		return max_len;
	}

	int len(vector<int> & nums, int n) {
		if (n == 0) return 1;
		if (l_[n] > 0) return l_[n];
		int size = nums.size();
		int max_len = 1;
		for (int j = 0; j < n; j++) {
			if (nums[n] > nums[j]) {
				max_len = max(max_len, len(nums, j) + 1);
			}
		}
		return l_[n] = max_len;
	}
private:
	vector<int> l_;
};

class Solution_iterative {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;

		vector<int> l(n, 1);

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (l[j] + 1 > l[i]) {
						l[i] = l[j] + 1;
					} 
				}
			}
		}
		return *max_element(l.begin(), l.end());
	}
};