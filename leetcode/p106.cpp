#include"Solutions.h"

// do p105 but reversely? 
// Let me try it:

TreeNode * p106::subbuilder(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_st) {
	if (in_start > in_end || post_st > inorder.size() - 1 || post_st < 0) return NULL;
	TreeNode * tmp = new TreeNode {postorder[post_st]}; 
	int i = in_start;
	while (i <= in_end) {
		if (inorder[i] == postorder[post_st]) break;
		i++;
	}
	tmp->left = subbuilder(inorder, postorder, in_start, i - 1, post_st - 1 - (in_end - i)); // - the amount in right tree!
	tmp->right = subbuilder(inorder, postorder, i + 1, in_end, post_st - 1);
	return tmp;
}

TreeNode* p106::buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0 || inorder.size() == 0) return NULL;
	TreeNode * ans;
	ans = subbuilder(inorder, postorder, 0, inorder.size() - 1, inorder.size() - 1);
	return ans;
}

void p106::test() {
	vector<int> a{ 9,3,15,20,7 };
	vector<int> b{ 9,15,7,20,3 };
	TreeNode * ans = buildTree(a, b);
	Tree t{ ans };
	t.BFT();
}