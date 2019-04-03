#include"Solutions.h"
class p163::Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> ans;
		int i;
		string tmp;
		// handle initially
		for (i = 0; i < nums.size(); i++) {
			if (i == 0) {
				while (i < nums.size() && nums[i] == lower) {
					i++, lower++;
				}
				if (i == nums.size())
					return {};
				if (lower + 1 == nums[i]) {
					tmp = to_string(lower);
				}
				else {
					tmp = to_string(lower) + "->" + to_string(nums[i] - 1);
				}
				ans.push_back(tmp);
			}
			// start with nums[i]
			int j = i + 1;
			while (j < nums.size() && nums[j] == nums[j - 1] + 1) j++;

			// nums[j] discountinue
			if (nums[i] + 2 == nums[j]) {
				tmp = to_string(nums[i] + 1);
			}
			else {
				tmp = to_string(nums[i] + 1) + "->" + to_string(nums[j] - 1);
			}
			ans.push_back(to_string(nums[i]));
			i = j;	
		}

		if (nums[i - 1] + 1 <= upper) {
			if (nums[i - 1] + 1 == upper) {
				tmp = to_string(nums[i - 1]);
				ans.push_back(tmp);
			}
			else {
				tmp = to_string(nums[i - 1]) + "->" + to_string(upper);
				ans.push_back(tmp);
			}
		}
		return ans;

	}
};

class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> res;
		long alower = lower, aupper = upper;
		for (int n : nums) {
			if (n == alower) {
				alower++;
			}
			else if (alower < n) {
				if (alower + 1 == n) {
					res.push_back(to_string(alower));
				}
				else {
					res.push_back(to_string(alower) + "->" + to_string(n - 1));
				}
				alower = n + 1;
			}
		}
		if (alower == aupper) res.push_back(to_string(alower));
		else if (alower < aupper)
			res.push_back(to_string(alower) + "->" + to_string(aupper));
		return res;
	}
};