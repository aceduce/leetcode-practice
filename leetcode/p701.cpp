#include"Solutions.h"
TreeNode* p701::insertIntoBST(TreeNode* root, int val) {
	if (!root) root =  new TreeNode{ val };
	if (root->val < val) root->right = insertIntoBST(root->right, val);
	if (root->val > val) root->left = insertIntoBST(root->left, val);
	return root;
}
