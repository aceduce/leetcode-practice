#include"Solutions.h"
// use a set (BST) 
// Brutal force
class p671::Solution {
public:
	void dfs(TreeNode * r, set<int> & vec) {
		if (!r) // find the values already
			return;
		dfs(r->left, vec);
		//rank++;
		vec.insert(r->val);
		dfs(r->right, vec);
	}

	int findSecondMinimumValue(TreeNode* root) {
		set<int> vec;
		dfs(root, vec);
		if (vec.size() < 2)
			return -1;
		return *(++vec.begin());
	}
};

/*

int min1;
	long ans = Long.MAX_VALUE;

	public void dfs(TreeNode root) {
		if (root != null) {
			if (min1 < root.val && root.val < ans) {
				ans = root.val;
			} else if (min1 == root.val) {
				dfs(root.left);
				dfs(root.right);
			}
		}
	}

*/