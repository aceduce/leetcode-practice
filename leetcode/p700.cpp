#include"Solutions.h"
TreeNode* p700::searchBST(TreeNode* root, int val) {
	if (!root) return NULL;
	if (root->val == val)
		return root;
	if (root->val < val)
		return searchBST(root->right, val);
	if (root->val > val)
		return searchBST(root->left, val);
	return NULL;
}