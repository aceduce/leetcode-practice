#include"Solutions.h"
// BFS and recursive
int p222::countNodes_recur(TreeNode* root) {
	// Use the recursive DFS
	if (root == NULL)
		return 0;
	return 1 + countNodes_recur(root->left) + countNodes_recur(root->right);
}

int p222::countNodes_iterative(TreeNode* root) {
	// Use the recursive DFS
	if (root == NULL)
		return 0;
	int count = 0;
	// Use BFS
	queue<TreeNode *> q;
	q.push(root);
	count++;
	while (!q.empty()) {
		TreeNode * tmp = q.front();
		q.pop();
		if (tmp->right) {
			q.push(tmp->right);
			count++;
		} 
		if (tmp->left) {
			q.push(tmp->left);
			count++;
		}
	}
	return count;
}