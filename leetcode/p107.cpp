#include"Solutions.h"
vector<vector<int>> p107::levelOrderBottom(TreeNode* root) {
 // use iterative method with queue
	queue<TreeNode *> q;
	vector<vector<int>> ans;
	if (root == NULL) return ans;
	q.push(root);
	while (!q.empty()) {
		vector<int> tmp;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			
			TreeNode * node{ q.front() };
			tmp.push_back(node->val);
			q.pop();
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		ans.insert(ans.begin(), tmp);
	}
	return ans;
}

void p107::test() {

}