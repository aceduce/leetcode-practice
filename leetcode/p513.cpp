#include"Solutions.h"
class p513::Solution {
public:
	// BFS the first element on the left
	// use iterative method
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode *> q;
		int level = 0;
		q.push(root);
		unordered_map<int, int> m;
		while (!q.empty()) {
			TreeNode * tmp = q.front();
			q.pop();
			level++;
			for (int i = q.size() - 1; i >= 0; i--) {
				if (tmp->left) {
					q.push(tmp->left);
					if(m.count(level) == 0)
						m[level] = tmp->left->val;
				}
				if (tmp->right) {
					q.push(tmp->right);
					if (m.count(level) == 0)
						m[level] = tmp->right->val;
				}
			}
			if (m.count(level) == 0) // no elements in this level
				level--;
		}
		return m[level];
	}
};

// this is from ZS
// https://leetcode.com/problems/find-bottom-left-tree-value/discuss/98777/8-lines-C%2B%2B-DFS-solution
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		int res = 0, maxLevel = -1;
		DFS(root, 0, maxLevel, res);
		return res;
	}

	void DFS(TreeNode* root, int level, int& maxLevel, int& res) {
		if (!root) return;
		DFS(root->left, level + 1, maxLevel, res);
		DFS(root->right, level + 1, maxLevel, res);
		if (level > maxLevel) res = root->val;
		maxLevel = max(maxLevel, level);
	}
};