#include "Solutions.h"

// a (list) return the sub-trees 
// here: we avoid to use the reference passing, and just create a new list from the heap
// default constructor is defined with val as initializer
vector<TreeNode*> subgen(int min, int max) {
	vector<TreeNode*> ans;
	if (min > max) return ans; // this will be null
	for (int rt = min; rt <= max; rt++) { // create left and right branches
		vector<TreeNode*> left = subgen(min, rt - 1);
		vector<TreeNode*> right = subgen(rt + 1, max);
		if (left.size() == 0 && right.size() == 0) {
			TreeNode * root = new TreeNode{ rt }; // just have one root!
			ans.push_back(root);
		}
		else if (left.size() == 0) {
			for (vector<TreeNode*>::iterator i = right.begin(); i != right.end(); i++) {
				TreeNode * root = new TreeNode(rt); // each tree root has to use a different dynamically allocated memoery
				root->right = *i; // saved the root node!
				ans.push_back(root);
			}
		}
		else if (right.size() == 0) {
			for (vector<TreeNode*>::iterator i = left.begin(); i != left.end(); i++) {
				TreeNode * root = new TreeNode(rt);
				root->left = *i;
				ans.push_back(root);
			}
		}
		else {// both side has elements
			for (vector<TreeNode*>::iterator i = left.begin(); i != left.end(); i++)
				for (vector<TreeNode*>::iterator j = right.begin(); j != right.end(); j++) {
					TreeNode * root = new TreeNode(rt);
					root->left = *i;
					root->right = *j;
					ans.push_back(root);
				}
		}
	}	
	return ans;
}

vector<TreeNode*> p95::generateTrees(int n) {
	vector<TreeNode*> ans = subgen(1, n);
	return ans;
}


void p95::test() {
	vector<TreeNode*> ans = generateTrees(3);
	for (vector<TreeNode*>::iterator i = ans.begin(); i != ans.end(); i++) {
		cout << " [ ";
		Tree t{ *i }; // root always comes first
		t.BFT();
		cout << " ] " << endl;
	}
	
}