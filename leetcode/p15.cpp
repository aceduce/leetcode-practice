# include<vector>
# include<algorithm>

using namespace std;

class Solution {
public:
	using num_t = vector<int>;

	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<num_t> ret;
		if (n < 3) return ret;

		int i = n - 1;
		while (i >= 2) {
			int target = -nums[i];                  // nice @grityxchen, save an add
			int k = i - 1;
			int j = 0;
			while (j < k) {
				int sum = nums[j] + nums[k];
				if (sum < target) j++;
				else if (sum > target) k--;
				else {
					ret.push_back({ nums[j], nums[k], nums[i] });
					while (j<k and nums[j] == nums[j + 1]) j++;     // inv: triples are unique
					while (j<k and nums[k] == nums[k - 1]) k--;
					j++;
					k--;
				}
			}
			while (i >= 2 and nums[i] == nums[i - 1]) i--;
			i--;
		}
		return ret;
	}
};