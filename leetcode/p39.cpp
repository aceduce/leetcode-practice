#include "Solutions.h"

// do we have a problem with tmp copy? this may be okay, if reference, need to copy?
void subComboSum(vector<int> & candidates, int target, int index, vector<vector<int>> & ans, vector<int> &tmp) {
	// tmp is the one either push_back or not
	
	if (target == 0) {// can push in 
		// not this one "candidates[index] == target"
		//tmp.push_back(candidates[index]);  // already did
		ans.push_back(tmp);
		return;
	}
	//if (candidates.size() == 0) return;

	for (int i = index; i < candidates.size(); i++) {
		// push in, run deep, push back
		if (candidates[i] > target) break; // cannot find val to insert ==> this will improve the performance!
		tmp.push_back(candidates[i]);
		subComboSum(candidates, target - candidates[i], i, ans, tmp); // can use duplicate
		tmp.pop_back(); // pop out candiate [i]
		// the iteration will bring to ignore this data point
	}
}

vector<vector<int>> p39::combinationSum(vector<int>& candidates, int target) {
	// my attempt try to use DP ==> xxx (if one needs to list out all possible numbers)
	// backtracking method!!
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> ans;
	vector<int> tmp;
	subComboSum(candidates, target, 0, ans, tmp);
	return ans;
}