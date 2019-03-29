#include"Solutions.h"
class p515::Solution {
public:
	// BFS is good enough
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode *> q;
		q.push(root);
		vector<int> ans;
		int level = 0;
		while (!q.empty()) {
			int v = INT_MIN;
			for (int i = q.size() - 1; i >= 0; i--) {
				TreeNode * tmp = q.front();
				q.pop();
				v = max(tmp->val, v);
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
			ans[level++] = v;
		}
		return ans;
	}
};