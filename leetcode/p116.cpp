#include"Solutions.h"
#include "p116.h"

// use iterative approach
// but this is not using constant space.. (a queue)
// interviewed showed
Node* p116::connect_queue(Node* root) {
	if (!root) return NULL;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node * tmp = q.front();
			q.pop();
			if (i != size - 1) { // not the last one!
				tmp->next = q.front();
			}
			else tmp->next = NULL;
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
		}
	}
	return root;
}

// recommended recursive solutions
Node* p116::connect_recur(Node * root) {
	if (!root) return NULL;
	if (root->left != NULL) {
		root->left->next = root->right;
	}
	// establish right child if necessary (the rightmost doenst' have this rquest)
	if (root->next != NULL && root->right!= NULL) { //missed the condition on root->right...
		root->right ->next= root->next->left;
	}
	connect_recur(root->left);
	connect_recur(root->right);
	return root;
}

// with next pointer, it is so easly
Node * p116::connect(Node * root) { // this is iterative method!!
	// BFS while 
	if (!root) return NULL;
	Node * cur = root;
	while (cur) {
		Node * level = cur;
		while (level) {
			if (level->left!= NULL) {
				level->left->next = level->right;
			}
			if (level->right != NULL && level->next != NULL) {
				level->right->next = level->next->left;
			}
			level = level->next;  //horizontally move
		}
		cur = cur->left;
	}

}

// Example
// BFS with 2 queues
void p116::connect_example(Node *root) {
	deque<Node*> q;
	if (root) q.push_back(root);
	while (!q.empty()) {
		deque<Node*> qq;
		Node* p = nullptr;
		while (!q.empty()) {
			Node* r = q.front();
			q.pop_front();
			if (r->left) qq.push_back(r->left);
			if (r->right) qq.push_back(r->right);
			if (p) p->next = r;
			p = r;
		}
		qq.swap(q);
	}
}
void p116::test() {
	Node *r = new Node { 1, NULL, NULL, NULL};
	r->left = new Node{ 2, NULL, NULL, NULL };
	r->right = new Node{ 3, NULL, NULL, NULL };
	r->left->left = new Node{ 4, NULL, NULL, NULL };
	r->left->right = new Node{ 5, NULL, NULL, NULL };
	r->right->left = new Node{ 6, NULL, NULL, NULL };
	r->right->right = new Node{ 7, NULL, NULL, NULL };
	connect_example(r);

}