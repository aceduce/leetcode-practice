#include "Solutions.h"
// recursive method
void p257::sub(TreeNode * r, string & tmp, vector<string> & ans) {
	if (!r) return;
	string s = "->" + to_string(r->val);
	//string t = tmp;
	if (tmp != "") tmp += s;
	else  tmp += to_string(r->val);
	if (!r->left && !r->right) {
		ans.push_back(tmp);
		return;
	}
	if (r->left) sub(r->left, tmp, ans);
	if (r->right) sub(r->right, tmp, ans);
}

vector<string> p257::binaryTreePaths(TreeNode* root) {
	if (!root) return {};
	vector<string> ans;
	string tmp;
	sub(root, tmp, ans);
}

void p257::test() {
	TreeNode r(1);
	r.left = &TreeNode(2);
	r.right = &TreeNode(3);
	r.left->right = &TreeNode(5);
	vector<string> ans = binaryTreePaths(&r);

}