#include"Solutions.h"

// like a parsing mechanism
TreeNode * p105::subbuilder(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end, int pre_start) {
	// exit conditions
	// = conditions are OKay
	if (in_start > in_end || pre_start >= preorder.size()) return NULL; // no treenode to build
																		// 
	TreeNode * p = new TreeNode{ preorder[pre_start] };
	int i; // index tracking
	for (i = in_start; i < in_end + 1; i++) {
		if (preorder[pre_start] == inorder[i]) {
			break;
		}
	}
	p->left = subbuilder(preorder, inorder, in_start, i - 1, pre_start + 1); // pre- following left tree
	p->right = subbuilder(preorder, inorder, i + 1, in_end, pre_start + (i - in_start) + 1);
	return p;
}

TreeNode* p105::buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0) return NULL;
	TreeNode * ans;
	ans = subbuilder(preorder, inorder, 0, inorder.size() - 1, 0);
	return ans;
}

void p105::test() {
	vector<int> a{ 3,9,20,15,7 };
	vector<int> b{ 9,3,15,20,7 };
	TreeNode * ans = buildTree(a, b);
	//Tree t{ ans };
	//t.BFT();
}