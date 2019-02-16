#include "BST.h"
# include <queue>
# include <iostream>

// for Breath and Depth first Traverse, no special need to data structure

// recursive 
void Tree::subDFT(TreeNode* root) {
	if (root == NULL) return;
	if (root->left != NULL) {
		subDFT(root->left);
	}
	else cout << "NULL->";

	cout << root->val << "->";
	if (root->right != NULL) {
		subDFT(root->right);
	}
	else cout << "NULL->";
}

// pop the tmp node, push left in queue, push right in queue


// use a queue here: breadth first
// in order (left-root-right)

/* considering null is done.*/

void Tree::subBFT(TreeNode* root) {
	if (root == NULL) return;
	// queue for level order traversal:
	queue<TreeNode *> q;
	q.push(root);
	while (q.empty() != true) {
		TreeNode * node = q.front();
		while (q.front() == NULL) {
			cout << " null " << "->";
			q.pop();
			if (q.empty() == true) return;
			node = q.front();
		}
		cout << node->val << "->";
		q.pop();
		if(node->left!= NULL) q.push(node->left);
		else if (node->left == NULL && node->right != NULL) q.push(NULL);

		if (node->right != NULL) q.push(node->right);
		else if (node->left != NULL && node->right == NULL) q.push(NULL);
	}
}
/**/

void Tree::BFT() {
	subBFT(root);
}

void Tree::DFT() {
	subDFT(root);
}

/*
// not considreing NULL
void Tree::subBFT(TreeNode* root) {
if (root == NULL) return;
// queue for level order traversal:
queue<TreeNode *> q;
q.push(root);
while (q.empty() != true) {
TreeNode * node = q.front();
cout << node->val << "->";
q.pop();
if(node->left!= NULL) q.push(node->left);
if (node->right != NULL) q.push(node->right);
}
}
*/