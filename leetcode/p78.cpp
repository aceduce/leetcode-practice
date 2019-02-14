#include"Solutions.h"

// backtracking question!
// how to trim it further??
// my attempt:
/*
void subsub(vector<int> & nums, vector<int> &tmp, vector < vector<int>> &ans, int indx) {
	if (indx == nums.size()) { // no duplicate then push-in for answer
		if (find(ans.begin(), ans.end(), tmp) == ans.end()) ans.push_back(tmp);
	}
	for (int i = indx; i < nums.size(); i++) {
		tmp.push_back(nums[i]);
		i++;
		subsub(nums, tmp, ans, i);
		tmp.pop_back(); // not using this nums[i]
		i--;
		subsub(nums, tmp, ans, i+1); // not using this element 
	}
}

vector<vector<int>> p78::subsets(vector<int>& nums) {
	vector<int> tmp;
	vector<vector<int>> ans;
	int indx = 0;
	subsub(nums, tmp, ans, indx);
	return ans;
}
*/

// this version is from the solution I
// a typical back-tracking method

void subsub(vector<int> & nums, vector<int> &tmp, vector < vector<int>> &ans, int indx) {
	// directly add the entry level tmp
	ans.push_back(tmp);
	for (int i = indx; i < nums.size(); i++) {
		tmp.push_back(nums[i]);
		subsub(nums, tmp, ans, i + 1);
		tmp.pop_back();
	}
}

// this version is from the solution II (need to implement both solutions!
// the key is no duplicate
/*
void subsub(vector<int> & nums, vector<int> &tmp, vector < vector<int>> &ans, int indx) {
if (indx == nums.size()) {
ans.push_back(tmp); // no concern for log-in
return;
}
// the key is no need for loop, natually prgressing ahead
tmp.push_back(nums[indx]); // take the num
subsub(nums, tmp, ans, indx + 1);
tmp.pop_back();
subsub(nums, tmp, ans, indx + 1); // not taking this element
}
*/


vector<vector<int>> p78::subsets(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> tmp;
	subsub(nums, tmp, ans, 0);
	return ans;
}

void p78::test() {
	vector<int> input{ 1,2,2 };
	vector<vector<int>> ans = subsets(input);
	for (int i = 0; i < ans.size(); i++) {
		cout << " [ ";
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << " ] " << endl;
	}
}