#include"Solutions.h"

// THINKING LEVEL FOR RECURSIVE quetions!!
// 3 steps:
// a. right attach to left leaf
// b. replace right with left
// c. set left to NULL

void p114::flatten(TreeNode* root) {
	// pre-order sequence
	// can be done using a stack DFS
	if (!root) return;
	// recursive thinking both set as flatten
	flatten(root->left);
	flatten(root->right);
	if (!root->left) return;
	// there's a root left node
	TreeNode * tmp = root->left;
	while (tmp->right!=NULL) {
		tmp = tmp->right;
	}
	tmp->right = root->right;
	root->right = root->left;
	root->left = NULL;
	return;
}

void p114::test() {

}