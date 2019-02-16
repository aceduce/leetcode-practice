#include"Solutions.h"

// https://leetcode.com/problems/recover-binary-search-tree/discuss/32559/detail-explain-about-how-morris-traversal-finds-two-incorrect-pointer
// key point is inline method should follow ascending;
// the way to keep pre node
// the way to tell which is the first wrong node, and which is the second wrong node

// should recite:
// in order traversal
void helper(TreeNode * r, TreeNode * &pre, TreeNode * &first, TreeNode *&second) {
	if (r == NULL) return;
	helper(r->left, pre, first, second);
	if (pre!= NULL && pre->val >= r->val) { // pre!= NULL is important!
		if(first == NULL) first = pre;
		second = r;
	}
	pre = r;
	helper(r->right, pre, first, second);
}

void p99::recoverTree(TreeNode* root) { // applies to all nodes!
	TreeNode * pre = NULL, *first = NULL, *second = NULL;
	helper(root, pre, first, second);
	// change value, not structure
	int tmp;
	tmp = first->val;
	first->val = second->val;
	second->val = tmp;
}

void p99::test() {
	TreeNode * head = new TreeNode{ 1 }; // vs TreeNode * head{nullptr}; TreeNode head{ 1 };
	//head->right = new TreeNode{ 4 };
	head->left = new TreeNode{ 3 };
	//head->right->right = new TreeNode{ 6 };
	head->left->right = new TreeNode{ 2 };
	Tree t{ head };
	t.BFT();
	cout << endl;
	// deep copy doesn't work for this way
	recoverTree(head);
	t.root = head; // has to use the same head
	t.BFT();
}