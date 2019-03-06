#include"Solutions.h"

// DFSinorder Traverse
// a simple implementation is push the stack with 
// Right , Node, Left, basically inversely--> take O(n)
// O(h) for recursive depth ==> this implementation
// https://leetcode.com/problems/binary-search-tree-iterator/discuss/52546/Short-C%2B%2B-O(n)-O(h)-space-solutions
class p173::BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		helper(root);
		// push every element into the stack
	}


	int next() {
		int ans = stack.top()->val;
		TreeNode * tmp = stack.top();
		stack.pop();
		helper(tmp->right);
		return ans;
	}

	
	bool hasNext() {
		return !stack.empty();
	}

	void helper(TreeNode * r) {
		if (!r) return;
		stack.push(r);
		helper(r->left);
	}
private:
	// stack<int> stack; this is good enough for making the stack with all elements
	stack<TreeNode *> stack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

void p173::test() {
	TreeNode r = TreeNode(7);
	r.left = &TreeNode(3);
	r.right = &TreeNode(15);
	r.right->left = &TreeNode(9);
	r.right->right = &TreeNode(20);
	BSTIterator* obj = new BSTIterator(&r);
	int param_1 = obj->next();
	bool param_2 = obj->hasNext();

}