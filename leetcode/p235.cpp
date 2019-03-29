#include"Solutions.h"
class p235::Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int parent_val = root->val;
		int p_val = p->val;
		int q_val = q->val;

		if (p_val > parent_val && q_val > parent_val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		if (p_val < parent_val && q_val < parent_val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else
			return root;
	}
};