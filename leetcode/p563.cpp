#include"Solutions.h"
class p563::Solution {
public:
	// return values and sum are different
	// sum only return left arm total
	int subfindTilt(TreeNode * r, int & sum) {
		if (!r)
			return 0;
		int left = subfindTilt(r->left, sum);
		int right = subfindTilt(r->right, sum);
		sum += abs(left - right);
		return r->val + left + right;
	}
	int findTilt(TreeNode* root) {
		if (!root)
			return 0;
		int sum = 0;
		subfindTilt(root, sum);
		return sum;
	}
};