#include"Solutions.h"

// iterative BFS
vector<int> p199::rightSideView(TreeNode* root) {
	queue<TreeNode*> q;
	vector<int> ans;
	if (root == NULL) return ans;
	q.push(root);
	while (!q.empty()) {
		for (int i = q.size() - 1; i >= 0; i--) {
			TreeNode * tmp = q.front();
			q.pop();
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
			if (i == 0) ans.push_back(tmp->val);
		}
	}
	return ans;
}

// 1,2,3,null,5,null,4
void p199::test() {
	TreeNode * r = new TreeNode{ 1 };
	r->left = new TreeNode{ 2 };
	r->right = new TreeNode{ 3 };
	r->left->right = new TreeNode{ 5 };
	r->right->right = new TreeNode{ 4 };
	vector<int> ans = rightSideView(r);

}