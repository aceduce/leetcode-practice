#include"Solutions.h"

int p110::helper(TreeNode * r) {
	if (r == NULL) return 0;
	int leftheight = helper(r->left);
	int rightheight = helper(r->right);
	if (abs(leftheight - rightheight) > 1) return -1; // unbalanced tree
	if (leftheight == -1 || rightheight == -1) return -1;
	return max(leftheight, rightheight) + 1;
}
bool p110::isBalanced(TreeNode* root) {
	if (!root) return true;
	return (helper(root) == -1) ? false : true;
}

void p110::test() {

}