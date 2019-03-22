#include"Solutions.h"
class Solution_my {
public:
	// in order traverse T: O(n)
	void sub(TreeNode * root, const int & k, int &rank, int & ans) {
		if (!root || ans != INT_MIN) // found the ansewr already
			return;
		sub(root->left, k, rank, ans);
		rank++;
		if (rank == k) {
			ans = root->val;
			return;
		}
		sub(root->right, k, rank, ans);
	}
	int kthSmallest(TreeNode* root, int k) {
		if (!root) return -1;
		int rank = 0;
		int ans = INT_MIN; // Java Interger may be better
		sub(root, k, rank, ans);
		return ans; // 
	}
};