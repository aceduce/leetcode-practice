#include"Solutions.h"
class p450::Solution {
public:
	TreeNode * findmax(TreeNode * root) {
		if (!root) return NULL;
		while (root->right) {
			root = root->right;
		}
		return root;
	}
	TreeNode * findmin(TreeNode * root) {
		if (!root) return NULL;
		while (root->left) {
			root = root->left;
		}
		return root;
	}

	// a basic data structure: delete node in BST
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return NULL;
		// root: left side highest

		// one child

		// (most difficult) two child: go to the left the highest;

		// no child: direct delete

		// two steps: find the node and delete
		if (root->val < key) { // delete elem in the right tree
			root->right = deleteNode(root->right, key);
		}
		else if (root->val > key) {
			root->left = deleteNode(root->left, key);
		}
		else if (root->val == key) {
			// no child: direct delete
			// one child
			if (!root->left) {
				return root->right;
			}
			else if (!root->right)
				return root->left;
			// (most difficult) two child: go to the left the highest;
			else if (root->left && root->right) {
				// find the left max / right min to replace this value
				// delte the max/min
				TreeNode * tmp = findmin(root->right);
				root->val = tmp->val;
				root->right = deleteNode(root->right, tmp->val);
				return root;
			}
		}
		return root;
	}
};