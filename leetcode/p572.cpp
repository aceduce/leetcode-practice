#include"Solutions.h"
// tree structure still follows BST (but just with equal numbers)
class p572::Solution_my {
public:
	void stack_DFS(TreeNode *r, vector<int> &s) {
		if (!r) return;
		TreeNode * tmp;
		stack<TreeNode *> trav;
		tmp = r;
		while (tmp != NULL || !trav.empty()) {
			// reach to the left-most
			while (tmp != NULL) {
				trav.push(tmp);
				tmp = tmp->left;
			}
			tmp = trav.top();
			trav.pop();
			s.push_back(tmp->val); // real traverse
			tmp = tmp->right;
		}
	}

	bool compareTree(TreeNode *a, TreeNode * b) {
		if (a == NULL && b == NULL) return true;
		else if (a == NULL || b == NULL) return false;
		// use stack based DFS method for practise
		vector<int> vec_a, vec_b;
		stack_DFS(a, vec_a);
		stack_DFS(b, vec_b);
		if (vec_a == vec_b) return true;
		else return false;
	}


	// same structure sub-tree
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == NULL && t == NULL) return true;
		if (s == NULL || t == NULL) return false;
		bool node = compareTree(s, t);
		bool left = isSubtree(s->left, t);
		bool right = isSubtree(s->right, t);
		if (left || right || node)
			return true;
		else return false;
	}
};


// special treatment 
// left leaf : lNULL, right leaf: rNULL
// https://leetcode.com/problems/subtree-of-another-tree/solution/
class p572::Solution_string {
public:
	string dfs(TreeNode * r, bool left) {
		if (!r) {
			if (left)
				return "lnull";
			else return "rnull";
		}
		// use pre-order
		return "#" + to_string(r->val) + "#" + dfs(r->left, true) + "#" + dfs(r->right, false);
	}
	// same structure sub-tree
	bool isSubtree(TreeNode* s, TreeNode* t) {
		string s_str = dfs(s, true);
		string t_str = dfs(t, true);
		if (s_str.find(t_str) != string::npos)
			return true;
		else return false;
	}
};

class p572::Solution {
public:
	bool isSubtree(TreeNode s, TreeNode t) {
		return traverse(s, t);
	}
	bool equals(TreeNode * x, TreeNode * y)
	{
		if (x == NULL && y == NULL)
			return true;
		if (x == NULL || y == NULL)
			return false;
		return x->val == y->val && equals(x->left, y->left) && equals(x->right, y->right);
	}
	bool traverse(TreeNode * s, TreeNode * t)
	{
		return  s != NULL && (equals(s, t) || traverse(s->left, t) || traverse(s->right, t));
	}
};