#include"Solutions.h"

// my attempt:
void p112::DFS(TreeNode *r, const int &sum, int accum_sum, bool &ans) {
	if (r == NULL) return;
	accum_sum += r->val;
	if (accum_sum == sum && !r->left && !r->right) {
		ans = true;
		return; // this is an answer
	}
	if (r->left) DFS(r->left, sum, accum_sum, ans);
	if (r->right) DFS(r->right, sum, accum_sum, ans);
}



bool p112::hasPathSum_DFS(TreeNode* root, int sum) {
	bool ans = false;
	if (!root) return ans;
	DFS(root, sum, 0, ans);
	return ans;
}

// total recursive method!! 
// 
bool p112::hasPathSum(TreeNode* root, int sum) {
	if (!root) return false;
	int partial_sum = sum - root->val;
	if (!root->left && !root->right && partial_sum ==0) return true; // found the path
	else {
		return hasPathSum(root->left, partial_sum) || hasPathSum(root->right, partial_sum);
	}
}

void p112::test() {

}