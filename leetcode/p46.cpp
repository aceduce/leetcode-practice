#include"Solutions.h"

// depth-first visit approach through recursive
// this case, we need to sort the array first

// consider using hashset(unordered_list)

void subpermute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &tmp) {
	if (nums.size() == tmp.size()) {
		// enough elemnts in the permutation now
		ans.push_back(tmp);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (find(tmp.begin(), tmp.end(), nums[i]) == tmp.end()) { // element is not in yet
			tmp.push_back(nums[i]);
			subpermute(nums, ans, tmp);
			tmp.pop_back();
		}
	}
}
vector<vector<int>> p46::permute(vector<int>& nums) {
	vector<int> tmp;
	vector<vector<int>> ans;
	subpermute(nums, ans, tmp);
	return ans;
}

void p46::test() {
	vector<int> inp{ 1, 2, 3 };
	vector<vector<int>> ans = permute(inp);
	for (vector<vector<int>>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << " [ ";
		for(auto &i: *i){
			cout << i << " ";
		}
		cout << " ] " <<endl;
	}

}