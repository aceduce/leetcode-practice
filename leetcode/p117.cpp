#include"Solutions.h"

// try with recursive
// reason this method does't work:
//     A
//   B   C
//  D E null F
Node* p117::connect_wrong(Node* root) {
	if (!root) return NULL;
	if (root->left!=NULL) {
		if (root->right!=NULL) root->left->next = root->right;
		else if (root->next!=NULL) {
			if (root->next->left!=NULL) root->left->next = root->next->left;
			else if (root->next->right!= NULL) root->left->next = root->next->right;
		}
	}
	if (root->right!=NULL && root->next!=NULL) {
		if (root->next->left!= NULL) root->right->next = root->next->left;
		else if (root->next->right!= NULL) root->right->next = root->next->right;
	}
	connect_wrong(root->left);
	connect_wrong(root->right);
	return root;
}

// use two loops horizontal and vertiacal
// anchor chead, chil, cur --> three poiners
// anchor so future can move downwords (breadth
// chil traverse 
// cur --> paret layer

Node * p117::connect(Node * root) {
	if (!root) return NULL;
	Node * chil = NULL;
	Node * curr = root; // like a parent node!!!
	Node * anchor = NULL;
	while (curr) { // vertical loop
		while (curr) {
			if (curr->left != NULL) {
				if (anchor == NULL) {
					anchor = curr->left;
				}
				else {
					chil->next = curr->left;
				}
				chil = curr->left; // alwasy use real node to traverse
			}
			if (curr->right != NULL) {
				if (anchor == NULL) {
					anchor = curr->right;
				}
				else {
					chil->next = curr->right;
				}
				chil = curr->right;
			}
			curr = curr->next;
		} 
		// finish one level move vertially now:
		// curr = anchor->left;  ==> next level is just anchor : not anchor left
		curr = anchor;
		anchor = NULL;
		chil = NULL;
	}
	return root;	
}

void p117::test() {
	Node *r = new Node{ 1, NULL, NULL, NULL };
	r->left = new Node{ 2, NULL, NULL, NULL };
	r->right = new Node{ 3, NULL, NULL, NULL };
	r->left->left = new Node{ 4, NULL, NULL, NULL };
	r->left->right = new Node{ 5, NULL, NULL, NULL };
	//r->right->left = new Node{ 6, NULL, NULL, NULL };
	r->right->right = new Node{ 7, NULL, NULL, NULL };
	connect(r);
	cout << "finished" << endl;
}