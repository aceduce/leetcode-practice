#include"Solutions.h"
// sounds like recursive call question
// use the range (min) (max)
bool subValid(TreeNode * r, long min, long max) {
	if (r == NULL) return true;
	if (min >= r->val || max <= r->val) return false;
	bool left = subValid(r->left, min, r->val); 
	bool right = subValid(r->right, r->val, max); // if write + 1 would be overflow
	return left && right;
}

bool p98::isValidBST(TreeNode* root) {
	return subValid(root, LONG_MIN, LONG_MAX); //need LONG to avoid input as 2147483647
}

void p98::test() {
	TreeNode * head = new TreeNode{ 5 }; // vs TreeNode * head{nullptr}; TreeNode head{ 1 };
	head->right = new TreeNode{ 4 };
	head->left = new TreeNode{ 1 };
	head->right->right = new TreeNode{ 6 };
	head->right->left = new TreeNode{ 3 };
	Tree t{ head };
	t.BFT();
	cout << endl<<"Is it a valid tree? " << isValidBST(head);
}