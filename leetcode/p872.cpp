#include"Solutions.h"
class p872::Solution {
private:
	vector<int> ans;
public:
	void dfs(TreeNode * r, vector<int> & a) {
		if (!r) return;
		if (!r->left && !r->right) {
			a.push_back(r->val);
			return;
		}
		if (r->left) dfs(r->left, a);
		if (r->right) dfs(r->right, a);
	}

	void dfs_stack(TreeNode * r, vector<int> & a) {
		stack<TreeNode *> stack;
		//stack.push(r);
		while (!stack.empty() || r) {
			while (r) {
				stack.push(r);
				r = r->left;
			}
			r = stack.top();
			stack.pop();
			if (!r->left && !r->right)
				a.push_back(r->val);
			r = r->right;
		}
	}


	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> a1, a2;
		dfs_stack(root1, a1);
		dfs_stack(root2, a2);
		if (a1 == a2)
			return true;
		else
			return false;
	}
};