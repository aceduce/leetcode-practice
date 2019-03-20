#include"Solutions.h"
class p968::Solution_DFS_Greedy {
public:
	//placing a camera with the deepest nodes first, and working our way up the tree.
	// Greedy method (bottom up)
	void dfs(TreeNode * chi, TreeNode * par, set<TreeNode *> &s, int &ans) {
		if (!chi)
			return;
		// DFS
		dfs(chi->left, chi, s, ans);
		dfs(chi->right, chi, s, ans);
		// cases of Insertion of Camera
		if (par == NULL && !s.count(chi) ||  // parent node NULL (root) and current node not marked
			!s.count(chi->left) ||
			!s.count(chi->right))  // left or right nodes not marked, then mark current node will cover them
		{
			ans++;
			// OKay to do duplicate insertion
			s.insert(chi->left);
			s.insert(chi);
			s.insert(chi->right);
			s.insert(par);
		}
	}

	int minCameraCover(TreeNode* root) {
		set<TreeNode*> seen;
		seen.insert(NULL); // leaf nodes will not add camera
		int ans = 0;
		dfs(root, NULL, seen, ans);
		return ans;
	}
};

class Solution_DP {
public:
	// State Machine
	// DP method from top-->down
	int minCameraCover(TreeNode* root) {

	}
};