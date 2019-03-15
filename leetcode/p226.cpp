#include"Solutions.h"
TreeNode* p226::invertTree(TreeNode* root) {
	if (!root) return NULL;
	TreeNode * left = root->left;
	TreeNode * right = root->right;
	root->left = invertTree(right);
	root->right = invertTree(left);
	return root;
}


TreeNode * p226::invertTree_iter(TreeNode * root) {
	if (root == NULL) return NULL;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode * current = q.front();
		q.pop();
		TreeNode * temp = current->left;
		current->left = current->right;
		current->right = temp;
		if (current->left != NULL) q.push(current->left);
		if (current->right != NULL) q.push(current->right);
	}
	return root;
}