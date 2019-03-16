#include"Solutions.h"

//Brutal force compare with DFS 
void p988::dfs(TreeNode * r, string & ans, string & tmp) {
	if (!r) return;
	string tmp_o = tmp;
	tmp += ('a' + r->val);
	if (!r->left && !r->right) { // leaf nodes
		reverse(tmp.begin(), tmp.end());
		if (ans.compare(tmp) > 0 && ans != "") ans = tmp;
		else if (ans == "")  ans = tmp;
		// should not do 
		// return;
	}
	else {
		dfs(r->left, ans, tmp);
		dfs(r->right, ans, tmp);
	}
	tmp = tmp_o;
	// need to get the tmp back to original case
}

// this is wrong, didn't understand the lexi... well..
void p988::dfs_w_level(TreeNode * r, string & ans, string & tmp, int lv, int & lvm) {
	if (!r || lv > lvm) return;
	string tmp_o = tmp;
	tmp += ('a' + r->val);
	if (!r->left && !r->right) { // leaf nodes
		// can record lvm
		lvm = (lvm < lv) ? lvm : lv;
		reverse(tmp.begin(), tmp.end());
		if (ans.compare(tmp) > 0 && ans != "") ans = tmp;
		else if (ans == "")  ans = tmp;
		// should not do 
		// return;
	}
	else {
		dfs_w_level(r->left, ans, tmp, lv + 1, lvm);
		dfs_w_level(r->right, ans, tmp, lv + 1, lvm);
	}
	tmp = tmp_o;
	// need to get the tmp back to original case
}
// considering optimization based on length...

string p988::smallestFromLeaf(TreeNode* root) {
	string ans = "~";
	if (!root) return "";
	string tmp = "";
	dfs(root, ans, tmp);
	int lvm = INT_MAX;
	dfs_w_level(root, ans, tmp, 0, lvm);
	return ans;
}



