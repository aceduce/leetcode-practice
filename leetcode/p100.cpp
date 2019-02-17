#include"Solutions.h"
bool p100::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	if (p->val != q->val) return false;
	//if (p->left == NULL && q->left != NULL) return false;
	//if (p->left != NULL && q->left == NULL) return false;
	if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
		return true;
	return false;
}

void p100::test() {

}