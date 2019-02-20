#include"Solutions.h"

// use middle to create height-balanced

TreeNode * p108::helper(vector<int> &num, int left, int right) {
	if (left > right) return NULL;
	if (num.size() == 0) return NULL;
	int mid = left + (right - left) / 2;
	TreeNode * r = new TreeNode{num[mid]};
	r->left = helper(num, left, mid - 1);
	r->right = helper(num, mid + 1, right);
	return r;
}
TreeNode* p108::sortedArrayToBST(vector<int>& nums) {
	return helper(nums, 0, nums.size() - 1);
}

void p108::test() {

}