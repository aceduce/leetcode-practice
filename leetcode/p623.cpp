#include"Solutions.h"
// my solution: using BFS
class p623::Solution_BFS_my {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		int level = 1;
		queue<TreeNode *> q;
		q.push(root);
		if (d == 1) { // deal with root
			TreeNode * tmp = new TreeNode{ v };
			tmp->left = root;
			return tmp;
		}
		while (!q.empty()) {
			int last = q.size() - 1;
			for (int i = last; i >= 0; i--) {
				TreeNode * tmp = q.front();
				q.pop();
				if (level == d - 1) { // begin to add row
					TreeNode * addl = new TreeNode{ v };
					TreeNode * addr = new TreeNode{ v };
					addl->left = tmp->left;
					addr->right = tmp->right;
					tmp->left = addl;
					tmp->right = addr;
				}
				else {
					if (tmp->left) q.push(tmp->left);
					if (tmp->right) q.push(tmp->right);
				}
			}
			if (level == d - 1) return root;
			level++;
		}
		return root;
	}
};