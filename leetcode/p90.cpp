#include"Solutions.h"

/*
// this version is from the solution II (need to implement both solutions!
// a taken bool is to avoid duplicate
// the key is no duplicate
void subsub(vector<int> & nums, vector<int> &tmp, vector < vector<int>> &ans, int indx, bool taken) {
	if (indx == nums.size()) {
		ans.push_back(tmp); // no concern for log-in
		return;
	}
	// the key is no need for loop, natually prgressing ahead
	// DUPLICATE comes from the case: {not taken first, then same element} vs { taken first}
	if (indx >= 1 && (nums[indx] ==nums[indx - 1]) && taken == false) { // duplicate: not taken before, take this one; elements are the same
		// no need to progress
	}
	else {
		tmp.push_back(nums[indx]); // take the num
		subsub(nums, tmp, ans, indx + 1, true);
		tmp.pop_back(); // pop back needs to be in this block
	}
	subsub(nums, tmp, ans, indx + 1, false); // not taking this element
}
*/

// implementation on Solution I
void subsub(vector<int> & nums, vector<int> &tmp, vector < vector<int>> &ans, int indx, bool taken) {
	ans.push_back(tmp);
	for (int i = indx; i < nums.size(); i++) {
		// avoid duplicate 
		if ((i >= 1) && nums[i] == nums[i - 1] & i!= indx) {} 
		else {
			tmp.push_back(nums[i]);
			subsub(nums, tmp, ans, i + 1, true);
			tmp.pop_back();
		}
		//subsub(nums, tmp, ans, i + 1, false);
	}
}

vector<vector<int>> p90::subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	vector<int> tmp;
	subsub(nums, tmp, ans, 0, true);
	//subsub(nums, tmp, ans, 0, false);
	return ans;
}

void p90::test() {
	vector<int> input{ 4,4,4,1,4 };
	vector<vector<int>> ans = subsetsWithDup(input);
	for (int i = 0; i < ans.size(); i++) {
		cout << " [ ";
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << " ] " << endl;
	}
}