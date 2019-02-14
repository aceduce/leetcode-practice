#include"Solutions.h"

// not ascending array
// not unique values
// use a boolean to detect if some element is used..
// a slight different implementaions
// okay to use & for tmp

void subPU(vector<int> & nums, vector<vector<int>> &ans, vector<int> tmp, vector<bool> &used) {
	if (nums.size() == tmp.size()) {
		ans.push_back(tmp);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue; // no need to ocntinue recursive stuff...
		if (used[i] == false) {
			tmp.push_back(nums[i]);
			used[i] = true;
			subPU(nums, ans, tmp, used);
			tmp.pop_back();
			used[i] = false;
		}

	}
}
vector<vector<int>> p47::permuteUnique(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> tmp;
	vector<bool> used(nums.size(), false);
	sort(nums.begin(), nums.end());
	subPU(nums, ans, tmp, used);
	return ans;
}

void p47::test() {
	vector<int> inp{ 1, 1, 1, 3 };
	vector<vector<int>> ans = permuteUnique(inp);
	for (vector<vector<int>>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << " [ ";
		for (auto &i : *i) {
			cout << i << " ";
		}
		cout << " ] " << endl;
	}


}