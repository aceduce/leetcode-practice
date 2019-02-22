#include"Solutions.h"

// a true thinking process very much similar to p124

int p543::helper(TreeNode * r, int &ans) {
	if (!r) return 0;
	int diam_l = helper(r->left, ans);
	int diam_r = helper(r->right, ans);
	if (r->left) diam_l++;
	if (r->right) diam_r++;
	ans = max(ans, diam_l + diam_r); // diam_r/l >= 0;
	int ret = max(diam_l, diam_r); // return one branch
	return ret;
}
int p543::diameterOfBinaryTree(TreeNode* root) {
	int ans = 0;
	helper(root, ans);
	return ans;
}

void p543::test() {

}