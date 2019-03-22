#include"Solutions.h"
class Solution_BF {
public:
	void dfs(TreeNode * r, unordered_map<int, int> freq) {
		if (!r) return;
		freq[r->val]++;
		dfs(r->left, freq);
		dfs(r->right, freq);
	}

	vector<int> findMode(TreeNode* root) {
		vector<int> ans;
		unordered_map<int, int> freq;
		int m = INT_MAX;
		dfs(root, freq);
		for (const auto & f : freq) {
			if (m > f.second) {
				m = f.second;
			}
		}
		for (const auto & f : freq) {
			if(f.second == m){
				ans.push_back(f.first);
			}
		}
		return ans;
	}
};

// without using extra-space
// https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/130066/Java-Solution-No-extra-space
// no extra space:
class Solution {
public:
	int maxCount = 1, count = 1;
	int prev = INT_MAX;
	void dfs(TreeNode * root, vector<int> &modes) {
		if (!root) return;
		dfs(root->left, modes);
		// previous is the same as this node
		// count ++;
		if (prev != INT_MAX && prev == root->val) {
			++count;
		}
		else // change the values now
			count = 1;

		if (maxCount <= count) { // need to update the count #
			if (maxCount < count)
				modes.clear(); // very critical, so future just keep the new ones...
			modes.push_back(root->val); // ok to add a new number with same counts
			maxCount = count;
		}
		prev = root->val;
		dfs(root->right, modes);
	}

	vector<int> findMode(TreeNode* root) {
		vector<int> ans;
		if (!root) return ans;
		dfs(root, ans);
		return ans;
	}
};