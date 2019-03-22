#include"Solutions.h"
class Solution {
public:
	// use queue for BFT
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root) return false;
		queue<TreeNode *> q;
		unordered_map<TreeNode * , TreeNode * > map;
		q.push(root);
		map[root] = NULL;
		TreeNode * pa, *pb;
		while (!q.empty()) {
			bool a = false, b = false;
			// need to make sure x & y have different parents
			for (int i = q.size() - 1; i >= 0; i--) {
				TreeNode * t = q.front();
				if (t->val == x) {
					a = true;
					pa = map[t];
				}
				if (t->val == y) {
					b = true;
					pb = map[t];
				}
				q.pop();
				if (t->left) {
					q.push(t->left);
					map[t->left] = t;
				}
				if (t->right) {
					q.push(t->right);
					map[t->right] = t;
				}
			}
			if (a && b && pa!= pb) return true;
		}
		return false;
	}
};