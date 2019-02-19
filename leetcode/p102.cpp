#include"Solutions.h"
//#include"Helper.h"
// HOW TO HAVE THE LEVEL ?
// calculate queue size in the middle

// iterative method (alternative use a current, back vector of nodes
// can also use DFS method
// https://www.youtube.com/watch?v=Tuij96VBdu8
vector<vector<int>> p102::levelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	if (root == NULL) return ans;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		int q_size = q.size(); // keep track of how many nodes in queue /in a level
		vector<int> tmp;
		while (q_size > 0) {
			tmp.push_back(q.front()->val);
			TreeNode * p = q.front();
			q.pop();
			q_size--;
			if (p->left != NULL) q.push(p->left);
			if (p->right != NULL) q.push(p->right);
		}
		// one level done:
		ans.push_back(tmp);
	}
	return ans;
}

/*

void DFS --> pretty cool method
	if (!root) return;
	while(ans.size() <= depth) ans.push_back({}); // inset empty rows
	DFS(root->left, depth + 1, ans);
	DFS(root->right, depth + 1, ans);
	ans[depth].push_back(root->val);
*/

void p102::test() {
	TreeNode * root = new TreeNode{ 3 };
	root->left = new TreeNode{ 9 };
	root->right = new TreeNode{ 20 };
	root->right->left = new TreeNode{ 15 };
	root->right->right = new TreeNode{ 7 };
	vector<vector<int>> ans = levelOrder(root);
	//Print2D(ans);
}