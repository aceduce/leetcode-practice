#include"Solutions.h"

// flags an array with two-dim

int * subRob(TreeNode * r) { // return the array
	int * ans = new int[2]{ 0 };
	if (!r) return ans; // ans [0] not steal, [1] steal this node
	int * left = subRob(r->left);
	int * right = subRob(r->right);
	// steal this node:
	int steal = r->val + left[0] + right[0];
	int nosteal = max(left[1], left[0]) + max(right[1], right[0]);
	ans[0] = nosteal, ans[1] = steal;
	return ans;
}

int p337::rob(TreeNode* root) {
	int ans = 0;
	if (!root) return ans;
	int * arr = subRob(root);
	ans = max(arr[0], arr[1]);
	return ans;
}

void p337::test() {
	// [3,2,3,null,3,null,1]
	TreeNode * r = new TreeNode{ 3 };
	r->left = new TreeNode{ 2 };
	r->right = new TreeNode{ 3 };
	r->left->right = new TreeNode{ 3 };
	r->right->left = new TreeNode{ 1 };
	cout << rob(r) << endl;
}