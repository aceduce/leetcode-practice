#include"Solutions.h"
//#include"Helper.h"
// use two stacks
vector<int> p145::postorderTraversal(TreeNode* root) {
	stack<TreeNode*> stack1;
	stack<TreeNode*> stack2;
	vector<int> ans;
	if (root == NULL) return ans;
	stack1.push(root);
	while (stack1.empty() != true) {
		TreeNode* tmp;
		tmp = stack1.top();
		stack1.pop();
		stack2.push(tmp);
		if (tmp->left != NULL) stack1.push(tmp->left);
		if (tmp->right != NULL) stack1.push(tmp->right);
	}
	while (stack2.empty() != true) {
		ans.push_back(stack2.top()->val);
		stack2.pop();
	}
	return ans;
}

void p145::test() {
	TreeNode * head = new TreeNode{ 1 }; // vs TreeNode * head{nullptr}; TreeNode head{ 1 };
	head->right = new TreeNode{ 2 };
	head->right->left = new TreeNode{ 3 };
	Tree t{ head };
	t.BFT();
	vector<int> ans = postorderTraversal(head);
//	printVec(ans);
}