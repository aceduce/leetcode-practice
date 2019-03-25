#include"Solutions.h"
class p449::Codec_fast {
	// Author: Huahua
	// Runtime: 19 ~ 26 ms (<93.31%)
	
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string s;
		serialize(root, s);
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int pos = 0;
		return deserialize(data, pos, INT_MIN, INT_MAX);
	}
private:
	void serialize(TreeNode* root, string& s) {
		if (!root) return;
		s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
		serialize(root->left, s);
		serialize(root->right, s);
	}

	TreeNode* deserialize(const string& s, int& pos, int curMin, int curMax) {
		if (pos >= s.size()) return nullptr;
		int val = *reinterpret_cast<const int*>(s.data() + pos);
		if (val < curMin || val > curMax) return nullptr;
		pos += sizeof(val);
		TreeNode* root = new TreeNode(val);
		root->left = deserialize(s, pos, curMin, val);
		root->right = deserialize(s, pos, val, curMax);
		return root;
	}
};

// another way to decode it:
class p449::Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize(in, INT_MIN, INT_MAX);
	}

private:
	// pre-order write:
	void serialize(TreeNode * r, ostringstream & out) {
		if (!r) {
			out << " # ";
			return;
		}
		out << r->val << " ";
		out << serialize(r->left);
		out << serialize(r->right);
	}

	// a different way to read (tell belonging to left sub-tree or right sub-tree)
	TreeNode* deserialize(istringstream & in, int min_val, int max_val) {
		string val;
		in >> val;
		if (val == "#") {
			return NULL;
		}
		int valint = stoi(val);
		if (valint < min_val || valint > max_val) return NULL;

		TreeNode * node = new TreeNode{ valint };
		node->left = deserialize(in, min_val, valint);
		node->right = deserialize(in, valint, max_val);
		return node;
	}
};

// fatest
// Author: Huahua
// Runtime: 19 ~ 26 ms (<93.31%)
class Codec_fast {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string s;
		serialize(root, s);
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int pos = 0;
		return deserialize(data, pos, INT_MIN, INT_MAX);
	}
private:
	void serialize(TreeNode* root, string& s) {
		if (!root) return;
		s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
		serialize(root->left, s);
		serialize(root->right, s);
	}

	TreeNode* deserialize(const string& s, int& pos, int curMin, int curMax) {
		if (pos >= s.size()) return nullptr;
		int val = *reinterpret_cast<const int*>(s.data() + pos);
		if (val < curMin || val > curMax) return nullptr;
		pos += sizeof(val);
		TreeNode* root = new TreeNode(val);
		root->left = deserialize(s, pos, curMin, val);
		root->right = deserialize(s, pos, val, curMax);
		return root;
	}
};