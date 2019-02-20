#include"Solutions.h"
/*
// use iterative method????
int p111::minDepth(TreeNode* root) {

	int depth = 0;
	queue<TreeNode *> q;
	if (!root) return 0;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		depth++;
		for (int i = 0; i < size; i++) {	
			TreeNode * r = q.front();
			q.pop();
			if (r == root) {
				if (!r->left && !r->right) return depth;
				else if (!r->left || !r->right) return depth + 1;
			}
			if (!r->left || !r->right) return depth; // root node is different
			q.push(r->left);
			q.push(r->right);
		}
		
	}
	return depth;
}
*/

// Only-One-SubTree root = subtree + 1, otherwise, min(left, right) + 1
int p111::minDepth(TreeNode* root) {
	if (!root) return 0;
	if (!root->left) return minDepth(root->right) + 1;
	else if (!root->right) return minDepth(root->left) + 1;
	else return min(minDepth(root->left), minDepth(root->right)) + 1;
}

void p111::test() {
	TreeNode * r = new TreeNode{ 0 };
	//r->left = new TreeNode{ 9 };
	//r->right = new TreeNode{ 20 };
	//r->left->left = new TreeNode{ 15 };
	//r->left->right = new TreeNode{ 7 };
	cout << minDepth(r) << endl;


}