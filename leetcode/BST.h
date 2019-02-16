#pragma once
//#include "Solutions.h"
// could be Undeclared indentifier compile error
#include <cstdlib>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



struct Tree {
	TreeNode *root;
	void DFT();
	void BFT();
	Tree(TreeNode* r) {
		root = new TreeNode(0);
		*root = *r; // this is a deep copy
	}
	Tree(const Tree &source) :Tree { (source.root) } {};
	~Tree() {
		delete root;
	}
private:
	void subDFT(TreeNode * r);
	void subBFT(TreeNode *r);
};
