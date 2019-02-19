#include"Solutions.h"

// considering using BFS... just visit right first
// recursive method
bool p101::isMirror(TreeNode * l, TreeNode * r) {
	//if (root == NULL) return true;
	if (l== NULL && r== NULL) return true;
	if (l == NULL || r == NULL) return false;
	bool out = isMirror(l->left, r->right);
	bool inside =isMirror(l->right, r->left);
	return out && inside && l->val == r->val;
}
bool p101::isSymmetric_recur(TreeNode* root) {
	if (root == NULL) return true;
	return isMirror(root->left, root->right);
}

// iterative method with queue: like a BFS
bool p101::isSymmetric(TreeNode* root) {
	if (root == NULL) return true;
	// iterative method
	// set queue, push root, push left, push right
	queue<TreeNode *> q;
	q.push(root->left);
	q.push(root->right);
	while (!q.empty()) {
		// double the workload!!
		TreeNode * t1 = q.front();
		q.pop(); // need immediately pop!!
		TreeNode * t2 = q.front();
		q.pop();
		if (t1 == NULL && t2 == NULL) continue; // ?
		if (t1 == NULL || t2 == NULL) return false;
		if (t1->val != t2->val) return false;
		q.push(t1->left);
		q.push(t2->right);
		q.push(t1->right);
		q.push(t2->left);
	}
	return true;
}


void p101::test() {
	TreeNode * root = new TreeNode{ 1 };
	root->left = new TreeNode{ 2 };
	root->right = new TreeNode{ 2 };
	root->left->left = NULL;
	root->left->right = new TreeNode{ 3 };
	root->right->left = NULL;
	root->right->right = new TreeNode{ 3 };
	cout << isSymmetric(root) << endl;

}