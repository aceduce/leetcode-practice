#include"Solutions.h"
// my thought: DFS the tree (inorder) twice
// first time: do summation
// second time keep a value and then - 2 * node->val
class p538::Solution{
public:
	int DFS_sum(TreeNode * r) {
		if (!r) return 0;
		int sleft = DFS_sum(r->left);
		int val = r->val;
		int sright = DFS_sum(r->right);
		return sleft + val + sright;
	}

	void DFS(TreeNode * r, int & sum) {
		if (!r)
			return;
		if (r->left) {
			DFS(r->left, sum);
		}
		sum -= r->val;
		r->val += sum;
		if (r->right) {
			DFS(r->right, sum);
		}

	}

	TreeNode* convertBST(TreeNode* root) {
		if (!root)
			return NULL;
		int total_sum = DFS_sum(root);
		DFS(root, total_sum);
		return root;
	}
};


class p538::Solution_RightFirst {
private:
	int sum = 0;

public:
	TreeNode * convertBST(TreeNode * root) {
		if (root != NULL) {
			convertBST(root->right);
			sum += root->val;
			root->val = sum;
			convertBST(root->left);
		}
		return root;
	}
};

class p538::Solution_ReverseStackDFS {
public:
	TreeNode * convertBST(TreeNode *root) {
		int sum = 0;
		TreeNode * node = root;
		stack<TreeNode *> stack;

		while (!stack.empty() || node != NULL) {
			/* push all nodes up to (and including) this subtree's maximum on
			 * the stack. */
			while (node != NULL) {
				stack.push(node);
				node = node->right;
			}

			node = stack.top();
			stack.pop();
			sum += node->val;
			node->val = sum;

			/* all nodes with values between the current and its parent lie in
			 * the left subtree. */
			node = node->left;
		}
		return root;
	}
};

