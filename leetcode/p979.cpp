#include"Solutions.h"
class p979::Solution {
//  excess number of coins in the subtree at or below this node: namely, the number of coins in the subtree, minus the number of nodes in the subtree. 
public:
	int ans;
	int distributeCoins(TreeNode * root) {
			ans = 0;
			dfs(root);
			return ans;
		}
	int dfs(TreeNode  * node) {
			if (node == NULL) return 0;
			int L = dfs(node->left);
			int R = dfs(node->right);
			ans += abs(L) + abs(R);
			return node->val + L + R - 1;
		}
};