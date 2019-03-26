#include"Solutions.h"
// obvious back-tracking mehtod 
class Solution_backtracking {
public:
	void subfind(vector<int> & nums, vector<int> & tmp, int indx, vector<vector<int>> & ans, set<vector<int>> & m) {
		int len = nums.size();
		// exit condition sequence is very important!!
		//if (indx >= len && tmp.size() >= 2) {
		if (tmp.size() >= 2) {
			if (m.count(tmp) == 0)
				ans.push_back(tmp);
			m.insert(tmp);
			// exit condition is very very important
			//return;
		}
		if (indx >= len)
			return;

		// consider optimize the duplicates
		for (int i = indx; i < len; i++) {
			if (tmp.size() == 0 || tmp.back() <= nums[i]) {
				tmp.push_back(nums[i]);
				subfind(nums, tmp, i + 1, ans, m);
				tmp.pop_back();
				//subfind(nums, tmp, i + 1, ans, m);
			}
			// no need for this one: as pop back next loop will natually deal with this
			// subfind(nums, tmp, i + 1, ans, m); // not using this element
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> tmp;
		int indx = 0;
		set<vector<int>> map;
		subfind(nums, tmp, indx, ans, map);
		return ans;
	}
};

class Solution_handle_duplicates { // cannot use sort as could be 1, 1....1,1 again and one cannot sort it....
public:
	void subfind(vector<int> & nums, vector<int> & tmp, int indx, vector<vector<int>> & ans, set<vector<int>> & m, int & pre) {
		int len = nums.size();
		// exit condition sequence is very important!!
		//if (indx >= len && tmp.size() >= 2) {
		if (tmp.size() >= 2) {
			ans.push_back(tmp);
		}
		if (indx >= len)
			return;

		// consider optimize the duplicates
		for (int i = indx; i < len; i++) {

			if (tmp.size() == 0 || (tmp.back() <= nums[i] && pre != nums[i])) {
				tmp.push_back(nums[i]);
				//pre = nums[i];
				subfind(nums, tmp, i + 1, ans, m, pre);
				tmp.pop_back();
				pre = nums[i];
				//subfind(nums, tmp, i + 1, ans, m);
			}
			// no need for this one: as pop back next loop will natually deal with this
			// subfind(nums, tmp, i + 1, ans, m); // not using this element
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> tmp;
		int indx = 0;
		set<vector<int>> map;
		int pre = INT_MAX;
		subfind(nums, tmp, indx, ans, map, pre);
		return ans;
	}
};

// https://leetcode.com/problems/increasing-subsequences/discuss/250280/C%2B%2B-Solution-with-explanation.
class Solution {
public:
	bool isUsed(vector<int> &A, int start, int index) {
		for (int i = start;i < index;i++)
			if (A[i] == A[index])
				return true;
		return false;
	}
	void backtracking(vector<vector<int>> &ans, vector<int>& A, vector<int> &curr, int index) {
		if (curr.size() > 1)
			ans.push_back(curr);
		if (index == A.size())
			return;

		// choices
		for (int i = index;i < A.size();i++) {
			if (curr.size() > 0 && A[i] < curr[curr.size() - 1]) // next Smaller
				continue;
			if (i > index && isUsed(A, index, i)) // repeating element
				continue;
			curr.push_back(A[i]);
			backtracking(ans, A, curr, i + 1);
			curr.pop_back();
		}
	}
	vector<vector<int>> findSubsequences(vector<int>& A) {
		vector<vector<int>> ans;
		vector<int> curr;
		backtracking(ans, A, curr, 0);
		//sort(ans.begin(),ans.end());
		return ans;
	}
};

/* passed supassing 100%
class Solution {
public:
	bool isUsed(vector<int> &A, int start, int index) {
		for (int i = start;i < index;i++)
			if (A[i] == A[index])
				return true;
		return false;
	}

	void subfind(vector<int> & nums, vector<int> & tmp, int indx, vector<vector<int>> & ans, set<vector<int>> & m) {
		int len = nums.size();
		// exit condition sequence is very important!!
		//if (indx >= len && tmp.size() >= 2) {
		if (tmp.size() >= 2) {
			ans.push_back(tmp);
		}
		if (indx >= len)
			return;

		// consider optimize the duplicates
		for (int i = indx; i < len; i++) {
			if (i > indx && isUsed(nums, indx, i)) // repeating element
					continue;
			if (tmp.size() == 0 || (tmp.back() <= nums[i])) {
				tmp.push_back(nums[i]);
				//pre = nums[i];
				subfind(nums, tmp, i + 1, ans, m);
				tmp.pop_back();
				//pre = nums[i];
				//subfind(nums, tmp, i + 1, ans, m);
			}
			// no need for this one: as pop back next loop will natually deal with this
			// subfind(nums, tmp, i + 1, ans, m); // not using this element
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> tmp;
		// sort(nums.begin(), nums.end());
		// cannot sort it
		int indx = 0;
		set<vector<int>> map;
		//int pre = INT_MAX;
		subfind(nums, tmp, indx, ans, map);
		return ans;
	}
};
*/