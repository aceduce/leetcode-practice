#include"Solutions.h"

class p559::Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class p559::Solution {
public:
	int maxDepth(Node* root) {
		queue<Node *> q;
		q.push(root);
		int level = 0;
		while (!q.empty()) {
			for (int i = q.size() - 1; i >= 0; i--) {
				Node * n = q.front();
				q.pop();
				if (n && n->children.size() > 0) {
					for (auto const & c : n->children) {
						q.push(c);
					}
				}
			}
			level++;
		}
		return level;
	}
};