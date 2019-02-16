# include"Solutions.h"


// non -recursive method:
// needs a stack structue!
// when pop, all left are processed already!

vector<int> p94::inorderTraversal(TreeNode* root) {
	stack<TreeNode*> workspace;
	vector<int> ans;
	TreeNode * cur = root;
	// stack empty means left is done; cur null means no right nodes
	while (workspace.empty() != true || cur!= NULL) {
		while (cur != NULL) {
			workspace.push(cur);
			cur = cur->left;
		}
		cur = workspace.top();
		ans.push_back(cur->val);
		workspace.pop();
		cur = cur->right;
	}
	return ans;
}

void p94::test() {
	TreeNode * head = new TreeNode{ 1 }; // vs TreeNode * head{nullptr}; TreeNode head{ 1 };
	head->right = new TreeNode{ 2 };
	head->right->left = new TreeNode{ 3 };
	Tree t{ head };
	t.BFT();
	vector<int> ans = inorderTraversal(head);
	//printVector(ans);

}