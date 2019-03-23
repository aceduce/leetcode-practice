#include"Solutions.h"
// Serialize the tree
// method 1: serialize into String
// method 2: serialize into long integer
// https://www.youtube.com/watch?v=JLK92dbTt8k
// used for method 1
class Solution {
public:
	// use pre-order pattern
	string serialize(TreeNode * r, unordered_map<string, int> &counts, vector<TreeNode *> & ans) {
		if (!r) return "#";
		// key is the serialized string patterns
		string key =  to_string(r->val) + "," + serialize(r->left, counts, ans) + "," + serialize(r->right, counts, ans);
		if (++counts[key] == 2)
			ans.push_back(r);
		return key;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, int> counts;
		vector<TreeNode *> ans;
		serialize(root, counts, ans);
		return ans;
	}
};

// used for method 2
// cannot passed as left shift negative values
class Solution {
public:
	// use pre-order pattern
	int serialize(TreeNode * r,
		unordered_map<long, int> &ids,
		unordered_map<int, int> & counts,
		vector<TreeNode *> & ans) {
		if (!r) return 0;
		// key is the serialized string patterns
		// elements < 65536
		long key = (static_cast<long>(r->val) << 32 |
			(serialize(r->left, ids, counts, ans) << 16) |
			(serialize(r->right, ids, counts, ans)));
		int id;
		auto it = ids.find(key);
		if (it == ids.end()) { // first insertion
			id = ids[key] = ids.size() + 1; // following sequence
		}
		else
			id = ids[key];
		if (++counts[id] == 2)
			ans.push_back(r);
		return id;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<int, int> counts;
		vector<TreeNode *> ans;
		unordered_map<long, int> ids;
		serialize(root, ids, counts, ans);
		return ans;
	}
};