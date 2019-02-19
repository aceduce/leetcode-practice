#include"Solutions.h"
#include"Helper.h"

// this approach doesnt' work for zigzag...
/*
*/


// insert from the top is very critical!!!
void DFS(TreeNode * r, vector<vector<int>> &ans, int depth) {
	if (r == NULL) return;
	while (ans.size() <= depth) ans.push_back({});
	// from left to right when depth is odd (0, 2, 4)...
	if (r->left) DFS(r->left, ans, depth + 1);
	if (r->right) DFS(r->right, ans, depth + 1);
	if (depth % 2 == 0) {
		ans[depth].push_back(r->val);
	}
	else
		ans[depth].insert(ans[depth].begin(), r->val); // where to put current is not that important, I guess
													   // need to insert at the front
}

// iterative method : still count the number of nodes in a layer

vector<vector<int>> p103::zigzagLevelOrder(TreeNode * root){
	int size = 0;
	list<TreeNode *> q;
	vector < vector<int>> ans; // answer format
	if (root == NULL) return ans;
	q.push_back(root);
	bool LeftToRight = true;
	// list has push_back and push_front
	while (!q.empty()) {
		size = q.size(); // the size of that layer
		vector<int> layer;
		if (LeftToRight) {
			for (int i = 0; i < size; i++) {
				// regular BFS
				TreeNode * tmp = q.front();
				q.pop_front();
				if (tmp == NULL) continue;
				layer.push_back(tmp->val);
				if (tmp->left) q.push_back(tmp->left);
				if (tmp->right) q.push_back(tmp->right);
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				// do it reversely
				// scan from right to left
				// insert from right to left at the front
				TreeNode * tmp = q.back();
				q.pop_back();
				if (tmp == NULL) continue;
				layer.push_back(tmp->val);
				if (tmp->right) q.push_front(tmp->right);
				if (tmp->left) q.push_front(tmp->left);
			}
		}
		LeftToRight = !LeftToRight;
		ans.push_back(layer);
	}
	return ans;
}
// use list, add front or add from back
vector<vector<int>> p103::zigzagLevelOrder_DFS(TreeNode* root) {
	// in main
	int depth = 0;
	vector<vector<int>> ans;
	DFS(root, ans, depth);
	return ans;
}

void p103::test() {
	TreeNode * r = new TreeNode{ 3 };
	r->left = new TreeNode{ 9 };
	r->right = new TreeNode{ 20 };
	r->right->left = new TreeNode{ 15 };
	r->right->right = new TreeNode{ 7 };
	vector<vector<int>> ans = zigzagLevelOrder(r);
	Print2D(ans);
}