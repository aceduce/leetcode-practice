#include"Solutions.h"
class p897::Solution {
public:
	// simplest method is to do an in-order-traverse and put into a vector
	// this method is visit and re-link
	TreeNode * cur;
	void inordertraverse(TreeNode * r) {
		if (!r) return;
		inordertraverse(r->left);
		r->left = NULL;
		cur->right = r;
		cur = r;
		inordertraverse(r->right);
	}

	TreeNode* increasingBST(TreeNode* root) {
		// visit and break left 
		// then track the rebuild tree
		TreeNode * ans;
		cur = ans;
		inordertraverse(root);
		return ans->right; // ans is not initizlized
	}
};