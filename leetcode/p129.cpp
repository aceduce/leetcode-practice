#include"Solutions.h"
// my attempt DFS
// BFS seems uncertain as how many digits are not certain
// DFS needs to convert string to number

void p129::DFS(TreeNode *r, int & tmp, int & ans) {
	if (r == NULL) return;
	if (r->left == NULL && r->right == NULL) { // a leaf node already
		ans += 10 * tmp + r->val + ans;
		return;
	}
	int t = tmp;
	tmp = 10 * tmp + r->val;
	if (r->left) {
		DFS(r->left, tmp, ans);
	}
	if (r->right) {
		DFS(r->right, tmp, ans);
	}
	tmp = t;

}
int p129::sumNumbers(TreeNode* root) {
	int ans = 0;
	int tmp = 0;
	DFS(root, tmp, ans);
	return ans;
}

void p129::test() {

}