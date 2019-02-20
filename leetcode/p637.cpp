#include"Solutions.h"

// want to simplify the passing
void p637::DFS(TreeNode *r, vector<double> &ans, int level, vector<vector<double>> &tmp) {
	if (r == NULL) return;
	while (ans.size() <= level) {
		ans.push_back({}); // match level numbers
		tmp.push_back({});
	}
	DFS(r->left, ans, level + 1, tmp);
	DFS(r->right, ans, level + 1, tmp);
	// take average
	int s = tmp[level].size();
	tmp[level].push_back(r->val);
	ans[level] = (ans[level] * s + r->val) / (s + 1);
}

void p637::DFS_save(TreeNode *r, vector<double> &ans, int level, vector<int> &size) {
	if (r == NULL) return;
	while (ans.size() <= level) {
		ans.push_back({}); // match level numbers
		size.push_back({});
	}
	DFS_save(r->left, ans, level + 1, size);
	DFS_save(r->right, ans, level + 1, size);
	// take average
	size[level]++;
	ans[level] = (ans[level] * (size[level] - 1) + r->val) / size[level];
}

vector<double> p637::averageOfLevels(TreeNode* root) {
	// use BFS visit and take average
	vector<double> ans;
	if (root == NULL) return ans;
	vector<int> tmp; // store the size
	//DFS(root, ans, 0, tmp);
	DFS_save(root, ans, 0, tmp);
	return ans;
}

void p637::test() {
	TreeNode * root = new TreeNode{ 3 };
	root->left = new TreeNode{ 9 };
	root->right = new TreeNode{ 20 };
	root->right->right = new TreeNode{ 7 };
	root->right->left = new TreeNode{ 15 };
	vector<double> ans = averageOfLevels(root);

}