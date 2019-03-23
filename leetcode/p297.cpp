#include"Solutions.h"
//https://www.youtube.com/watch?v=JL4OjKV_pGE
class p297::Codec_String {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		// ostringstream is like a stream builder
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize(in);
	}
private:
	void serialize(TreeNode * r, ostringstream & out) {
		if (!r) {
			out << "# ";
			return;
		}
		out << r->val << " ";
		out << serialize(r->left);
		out << serialize(r->right);
	}

	TreeNode * deserialize(istringstream & in) {
		string val;
		in >> val;
		if (val == "#")
			return NULL;
		TreeNode * node = new TreeNode(stoi(val));
		node->left = deserialize(in);
		node->right = deserialize(in);
		return node;
	}
};

// Author: Huahua
// Running time: 23 ms (beat 98.07%)
class Codec_Binary {
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
		return deserialize(in);
	}
private:
	enum STATUS {
		ROOT_NULL = 0x0,
		ROOT = 0x1,
		LEFT = 0x2,
		RIGHT = 0x4
	};

	void serialize(TreeNode* root, ostringstream& out) {
		char status = 0;
		if (root) status |= ROOT;
		if (root && root->left) status |= LEFT;
		if (root && root->right) status |= RIGHT;
		out.write(&status, sizeof(char));
		if (!root) return;
		out.write(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
		if (root->left) serialize(root->left, out);
		if (root->right) serialize(root->right, out);
	}

	TreeNode* deserialize(istringstream& in) {
		char status;
		in.read(&status, sizeof(char));
		if (!status & ROOT) return nullptr;
		auto root = new TreeNode(0);
		in.read(reinterpret_cast<char*>(&root->val), sizeof(root->val));
		root->left = (status & LEFT) ? deserialize(in) : nullptr;
		root->right = (status & RIGHT) ? deserialize(in) : nullptr;
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));