#include"Solutions.h"

// use an iterative method with stack with DFS .. not successful...
int p104::maxDepth(TreeNode* root) {
	// use recursive method
	if (root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
	/*
	int ans = INT_MIN;
	stack<TreeNode *> stack;
	if (root == NULL) return 0;
	stack.push(root);
	TreeNode * p;
	p = stack.top();
	int current_dep = 1;
	while (!stack.empty() && p!= NULL) {
		int depth = current_dep;
		p = stack.top();
		stack.pop();
		while (p->left != NULL) {
			stack.push(p->left);
			p = p->left;
			depth++;
		}
		p = p->right;
		if (p != NULL) depth++;
		if (p == NULL) depth--;
		current_dep = depth;
		ans = (ans < depth) ? depth : ans;
	}
	return ans;
	*/
}

void p104::test() {
	TreeNode * r = new TreeNode{ 3 };
	r->left = new TreeNode{ 9 };
	r->right = new TreeNode{ 20 };
	r->right->left = new TreeNode{ 15 };
	r->right->right = new TreeNode{ 7 };
	cout << maxDepth(r) << endl;
}