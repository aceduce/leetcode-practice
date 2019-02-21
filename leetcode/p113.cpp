#include"Solutions.h"
//#include"Helper.h"
// solvable, but not the best
void p113::DFS(TreeNode * r, int accum_sum, const int sum, vector<vector<int>> &ans, vector<int> tmp) {
	if (!r) return;
	accum_sum = r->val + accum_sum;
	tmp.push_back(r->val);
	if (accum_sum == sum && !r->left && !r->right) {
		ans.push_back(tmp);
		//tmp.clear();
		return;
	}
	if (r->left) DFS(r->left, accum_sum, sum, ans, tmp);
	if (r->right) DFS(r->right, accum_sum, sum, ans, tmp);
}

vector<vector<int>> p113::pathSum_my(TreeNode* root, int sum) {
	
	vector<vector<int>> ans;
	if (!root) return ans;
	vector<int> tmp;
	DFS(root, 0, sum, ans, tmp);
	return ans;
}

void p113::helper(TreeNode * r, int sum, vector<int> &tmp, vector<vector<int>> &ans) {
	// like the question before in 112, but here the keep is how to make tmp intact!!
	if (!r) return;
	int partial_sum = sum - r->val;
	if (!r->left && !r->right && partial_sum == 0) {
		ans.push_back(tmp);
		ans.back().push_back(r->val); // easier way than 3 lines of codes
	}
	tmp.push_back(r->val);
	helper(r->left, partial_sum, tmp, ans);
	helper(r->right, partial_sum, tmp, ans);
	tmp.pop_back();
}

vector<vector<int>> p113::pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ans;
	if (!root) return ans;
	vector<int> tmp;
	helper(root, sum, tmp, ans);
	return ans;
}


void p113::test() {
	TreeNode * r = new TreeNode{ 5 };
	r->left = new TreeNode{ 4 };
	r->right = new TreeNode{ 8 };
	r->right->left = new TreeNode{ 13 };
	r->right->right = new TreeNode{ 4 };
	r->right->right->left = new TreeNode{ 5 };
	r->right->right->right = new TreeNode{ 1 };
	r->left->left = new TreeNode{ 11 };
	r->left->left->left = new TreeNode{ 7 };
	r->left->left->right = new TreeNode{ 2 };
	vector<vector<int>> ans = pathSum(r, 22);
	//r->left->right = new TreeNode{ 7 };
	//Print2D(ans);
}