#include"Solutions.h"
// too many corner cases...
// flag is tricky
class Solution_my {
public:
	bool isCompleteTree(TreeNode* root) {
		if (!root) return false;
		queue<TreeNode *> q;
		q.push(root);
		// if last level is NULL 
		// but the next level has no children, it's still good
		bool level = true;
		while (!q.empty()) {
			bool flag = false;
			if (!level) flag = true;
			int last = q.size() - 1;
			for (int i = q.size() - 1; i >= 0; i--) {
				TreeNode * tmp = q.front();
				q.pop();
				bool l, r;
				l = false, r = false;
				if (tmp->left) {
					q.push(tmp->left);
					l = true;
					if (flag) return false;
				}
				if (tmp->right) {
					q.push(tmp->right);
					r = true;
					if (flag) return false;
				}
				if (i != last && !level && (l || r)) return false;
				if (!l && r) return false;
				if (!r) level = false;
				if (r) level = true;
			}
		}
		return true;
	}
};

/* lazy to correct the grammars

class Solution {
	public boolean isCompleteTree(TreeNode root) {
		List<ANode> nodes = new ArrayList();
		nodes.add(new ANode(root, 1));
		int i = 0;
		while (i < nodes.size()) {
			ANode anode = nodes.get(i++);
			if (anode.node != null) {
				nodes.add(new ANode(anode.node.left, anode.code * 2));
				nodes.add(new ANode(anode.node.right, anode.code * 2 + 1));
			}
		}

		return nodes.get(i - 1).code == nodes.size();
	}
}

class ANode {  // Annotated Node
	TreeNode node;
	int code;
	ANode(TreeNode node, int code) {
		this.node = node;
		this.code = code;
	}
}

*/