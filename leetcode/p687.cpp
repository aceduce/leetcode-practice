#include"Solutions.h"

// return one branch
int p687::helper(TreeNode * r, int & ans) {
	if (!r) return 0;
	int lmax = 0, rmax = 0; // other wise left and right are empty, value is too small..
	if (r->left != NULL) {
		lmax = helper(r->left, ans);
		if (r->val == r->left->val)
			lmax++;
		else {
			lmax = 0;
		}
	}
	
	if (r->right!= NULL) {
		rmax = helper(r->right, ans);
		if (r->val == r->right->val)
			rmax++;
		else rmax = 0;
	}
	
	int ret;
	ret = max(lmax, rmax); // return has to be one-sided
	ans = (ans < ret) ? ret : ans;
	ans = max(lmax + rmax, ans); // cases where left and right bride togher
	return ret;
}

int p687::longestUnivaluePath_my(TreeNode* root) {
	int ans = 0;
	helper(root, ans);
	return ans;
}


// good coding habbits
int p687::univaluePath(TreeNode *r, int & ans) {
	if (!r) return 0;
	int left = univaluePath(r->left, ans);
	int right = univaluePath(r->right, ans);
	int pl = 0, pr = 0;
	if (r->left && r->val == r->left->val) pl = left + 1;
	if (r->right&& r->val == r->right->val) pr = right + 1;
	ans = max(ans, pl + pr); // take the sum
	return max(pl, pr);
}
int p687::longestUnivaluePath(TreeNode * root) {
	if (!root) return 0;
	int ans = 0;
	univaluePath(root, ans);
	return ans;
}

void p687::test() {
	TreeNode * r = new TreeNode{ 1 };
	r->left = new TreeNode{ 4 };
	r->right = new TreeNode{ 5 };
	r->left->left = new TreeNode{ 4 };
	r->left->right = new TreeNode{ 4 };
	r->right->right = new TreeNode{ 5 };
	cout << longestUnivaluePath(r) << endl;
}