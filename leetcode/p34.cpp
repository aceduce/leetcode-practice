#include "Solutions.h"

// search array with duplicates
vector<int>p34::searchRange(vector<int>& nums, int target) {
  // my attempt:
	// complexity could be O(n) in the search nearby
  // binary search:
	vector<int> ans;
	if (nums.empty()) {
		ans.push_back(-1);
		ans.push_back(-1);
		return  ans;
	}
	int n = nums.size();
	int left = 0;
	int right = n - 1;
	int mid;
	int start, end;
	int pos = -1;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (nums[mid] == target) {
			pos = mid;
			searchneighbor(pos, nums, ans, target);
			return ans;
		}
		if (nums[mid] < target) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	if (nums[left] == target) pos = left;
	if (nums[right] == target) pos = right;
	if (pos != -1) {
		searchneighbor(pos, nums, ans, target);
		return ans;
	} 
	ans.push_back(-1);
	ans.push_back(-1);
	return  ans;
}

void p34::searchneighbor(const int & pos, vector<int> & nums, vector<int> &ans, const int & target) {
	int start = pos, end = pos;
	while (start >= 0 && nums[start] == target) {
		start--;
	}
	start++;
	while (end <= nums.size()-1 &&nums[end] == target) {
		end++;
	}
	end--;
	ans.push_back(start);
	ans.push_back(end);
}