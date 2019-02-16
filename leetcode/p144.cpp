# include"Solutions.h"
//#include "Helper.h"

vector<int> p144::preorderTraversal(TreeNode* root) {
	stack<TreeNode*> stack;
	vector<int> ans;
	// TreeNode * cur = new TreeNode{ root };
	TreeNode * cur = root;
	while (!stack.empty() || cur != NULL) {
		while (cur != NULL) {
			ans.push_back(cur->val);
			stack.push(cur);
			cur = cur->left;
		}
		cur = stack.top();
		stack.pop();
		cur = cur->right;
	}
	return ans;
}

void p144::test() {
	TreeNode * head = new TreeNode{ 1 }; // vs TreeNode * head{nullptr}; TreeNode head{ 1 };
	head->right = new TreeNode{ 2 };
	head->right->left = new TreeNode{ 3 };
	Tree t{ head };
	t.BFT();
	vector<int> ans = preorderTraversal(head);
	//printVec(ans);

}