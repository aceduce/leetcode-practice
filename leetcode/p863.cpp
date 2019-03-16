#include"Solutions.h"
// Annotate Parents:
void p863::dfs_map(TreeNode * ch, TreeNode * pa, unordered_map<TreeNode *, TreeNode *> & m) {
	if (ch == NULL) return;
	m.insert({ ch, pa });
	dfs_map(ch->left, ch, m);
	dfs_map(ch->right, ch, m);
}
// going down? but how do we go up??
vector<int> p863::distanceK(TreeNode* root, TreeNode* target, int K) {
	// child --> parents, a gap of 1 level
	// this is for the whole tree:
	unordered_map<TreeNode *, TreeNode *> map;
	vector<int> ans;
	dfs_map(root, NULL, map);
	// use a queue to contain left/right childs, parents
	queue<TreeNode *> q;
	// Manually designed a pattern
	q.push(NULL);  // going from the top
	q.push(target); // going from the target

	set<TreeNode *> seen; // a hashset of seen node (won't double count)
	seen.insert(target);
	seen.insert(NULL);
	int level = 0;
	// search updward for parents
	while (!q.empty()) {
		TreeNode * tmp = q.front();
		q.pop();
		// queue at the beginning only store the same level nodes
		if (tmp == NULL) {
			if (level == K) { // begin to insert into ans
				while (!q.empty()) {
					int val = q.front()->val;
					ans.push_back(val);
					q.pop();
				}
				return ans;
			}
			q.push(NULL);
			level++;
		}
		else {
			// search at the breadth
			// at same level from target
			// [a, b, c, d, e, f, g] NULL [h, i, j, k, l] NULL
			if (!seen.count(tmp->left)) { // NULL won't get in
				seen.insert(tmp->left);
				q.push(tmp->left);
			}
			if (!seen.count(tmp->right)) { // NULL won't get in
				seen.insert(tmp->right);
				q.push(tmp->right);
			}
			if (!seen.count(map[tmp])) { // NULL won't get in
				seen.insert(map[tmp]);
				q.push(map[tmp]);
			}
		}
	}
	return ans;
}

// Approach #2:
// An DFS labeling the # of levels needed to reach the target node


class p863::Solution2 {
private:
	// this is like a global variale
	vector<int> ans;
public:
	// -1 means didn't find the target node
	// this DFS is independently going deep with one branch: looking for target
	// find ans is cross!
	int dfs(TreeNode * r, TreeNode * target, const int K) {
		if (r == NULL)
			return -1;
		if (r == target) { // this is essentially looking downwards:
			add_nodes(r, 0, K);
			return 1;
		}
		else { // not the target node, but could be a parent node
			int L = dfs(r->left, target, K);
			int R = dfs(r->right, target, K);
			if (L != -1) {
				// target is on left
				// K levels node is at left
				if (L == K) ans.push_back(r->val); // root node is K distance to target
				else add_nodes(r->right, L + 1, K); // the K dist node is actually on the right
				return L + 1;
			}
			else if (R != -1) {
				if (R == K) ans.push_back(r->val);
				else add_nodes(r->left, R + 1, K);
				return R + 1;
			}
			else {
				return -1; // do not exist on left or right...
			}

		}

	}

	// this is adding the levels with gap K - dis
	// when this function gets called, this is cross - root case
	void add_nodes(TreeNode * r, int dis, const int K) {
		if (!r) return;
		if (dis == K) {
			ans.push_back(r->val);
			return;
		}
		add_nodes(r->left, dis + 1, K);
		add_nodes(r->right, dis + 1, K);
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		dfs(root, target, K);
		return ans;
	}
};


