#include"Solutions.h"
// standing at a node: consider two cases:
// with root till (previous questions) & with current as start

// typical problem in submission, needs two sum... this is wrong...
int p437::helper_wrong(TreeNode * r, const int sum, int ps, int &ans) { // return the number of paths
	if (!r) return 0;
	int partial = ps - r->val;
	//int ans = 0;
	if (partial == 0) ans += 1;  // no need to check left and right child
	// consider both partial sum and not partial sum (include and not incude this node)_
	helper_wrong(r->left, sum, partial, ans);
	helper_wrong(r->right, sum, partial,ans);
	helper_wrong(r->left, sum, sum, ans); // still duplicate in single tree example
	helper_wrong(r->right, sum, sum, ans);
	return ans;
}

// totally just deal with partia_sum/ from this root!
int p437::true_helper(TreeNode * r, int sum) {
	if (!r) return 0;
	int ans = 0;
	int partial_sum = sum - r->val;
	if (partial_sum == 0) ans++;
	ans += true_helper(r->left, partial_sum);
	ans += true_helper(r->right, partial_sum);
	return ans;
}
int p437::pathSum(TreeNode* root, int sum) {
	if (!root) return 0;
	// this partition separte the problem completely!!
	return 	true_helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

void p437::test() {
	/* sample tree
	TreeNode * r = new TreeNode{ 10 };
	r->left = new TreeNode{ 5 };
	r->right = new TreeNode{ -3 };
	r->left->left = new TreeNode{3 };
	r->left->right = new TreeNode{ 2 };
	r->right->right = new TreeNode{ 11 };
	r->left->left->left = new TreeNode{ 3 };
	r->left->right->right = new TreeNode{ -2 };
	r->left->right->right = new TreeNode{ 1 };
	*/
	TreeNode * r = new TreeNode{ 1 };
	r->right = new TreeNode{ 2 };
	r->right->right = new TreeNode{ 3 };
	r->right->right->right = new TreeNode{ 4 };
	r->right->right->right->right = new TreeNode{ 5 };

	cout << pathSum(r, 3);
	cout << endl;
}