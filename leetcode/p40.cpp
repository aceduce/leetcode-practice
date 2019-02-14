# include "Solutions.h"


void helper_comboSum2(vector<int> & candidates, int target, int indx, vector<vector<int>>& ans, vector<int> tmp) {
	if (target == 0) {
		ans.push_back(tmp);
		return;
	}
	for (int i = indx; i < candidates.size(); i++) {
		// push in, run deep, push back
		if (target < candidates[i]) return;
		if (i != indx && candidates[i] == candidates[i - 1]) continue; // skip duplicate candidate i
		// the graphic views!!
		tmp.push_back(candidates[i]);
		// avoid duplicates [2, 2' ...] for loop goes [2'...] 
		// push 2, avoid 2' (inside call func, and loop) == not push, this loop just pop, and in loop next round push into 2'
		// just do one is enough, suggested to avoid it by at this loop
		helper_comboSum2(candidates, target - candidates[i], i + 1, ans, tmp); // move forward by one index once pushed in; this is different from p39
		tmp.pop_back();
	}

}
vector<vector<int>> p40::combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> tmp;
	sort(candidates.begin(), candidates.end());
	helper_comboSum2(candidates, target, 0, ans, tmp);
	return ans;
}
