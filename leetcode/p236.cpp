#include"Solutions.h"
class p236::Solution {
public:
	// a node can be an descend of itself
	array<bool, 2> subLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode * &ans) {
		if (!root || ans != NULL) return { false, false }; // find answer or reach the leaf already
		bool hasP = false, hasQ = false;
		array<bool, 2> resL = subLCA(root->left, p, q, ans);
		array<bool, 2> resR = subLCA(root->right, p, q, ans);

		if (root == p) hasP = true;
		if (root == q) hasQ = true;

		resR[0] = resR[0] || resL[0] || hasP;
		resR[1] = resR[1] || resL[1] || hasQ;

		if (ans == NULL && ((resR[0]) && resR[1]))
			ans = root;
		return { hasP || resR[0], hasQ || resR[1] };
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode * ans = NULL;
		subLCA(root, p, q, ans);
		return ans;
	}
};

/* VERY SMART WAY
// Left Recursion. If left recursion returns true, set left = 1 else 0
		int left = this.recurseTree(currentNode.left, p, q) ? 1 : 0;

		// Right Recursion
		int right = this.recurseTree(currentNode.right, p, q) ? 1 : 0;

		// If the current node is one of p or q
		int mid = (currentNode == p || currentNode == q) ? 1 : 0;


		// If any two of the flags left, right or mid become True
		if (mid + left + right >= 2) {
			this.ans = currentNode;
		}
*/

/*
 // Ancestors set() for node p.
		Set<TreeNode> ancestors = new HashSet<>();

		// Process all ancestors for node p using parent pointers.
		while (p != null) {
			ancestors.add(p);
			p = parent.get(p);
		}

		// The first ancestor of q which appears in
		// p's ancestor set() is their lowest common ancestor.
		while (!ancestors.contains(q))
			q = parent.get(q);
		return q;
	}
*/

