#include"Solutions.h"
class p449::Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		// use pre-order visit
		if (!root)
			return "#";
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

	}
};