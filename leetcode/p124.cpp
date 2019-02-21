#include"Solutions.h"
// no direction graph
// return only one sided tree: so that it can be connected
// not very intuitive...

int p124::helper(TreeNode * root, int & ans) {
	// return unisisded tree
	if (!root) return INT_MIN;
	int leftmax = max(0, helper(root->left, ans)); // if smaller don't include
	int rightmax = max(0, helper(root->right, ans));
	if (ans < leftmax + rightmax + root->val) {
		ans = leftmax + rightmax + root->val;
	}
	return root->val + max(leftmax, rightmax);
}
int p124::maxPathSum(TreeNode* root) {
	int ans = 0;
	ans = helper(root, ans);
	return ans;
}

void p124::test() {
	TreeNode * r = new TreeNode{ 1 };
	r->left = new TreeNode{ 2 };
	r->right = new TreeNode{ 3 };
	cout << maxPathSum(r) << endl;

}