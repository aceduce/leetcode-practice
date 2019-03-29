#include"Solutions.h"
class p404::Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (!root) return true;
		bool left = true, right = true;
		int val_l = INT_MAX;
		int val_r = INT_MAX;
		if (root->left) {
			left = isUnivalTree(root->left);
			val_l = root->left->val;
			if (val_l != root->val)
				return false;
		}

		if (root->right) {
			right = isUnivalTree(root->right);
			val_r = root->right->val;
			if (val_r != root->val)
				return false;
		}
		if (left && right)
			return true;
		else return false;
	}
};