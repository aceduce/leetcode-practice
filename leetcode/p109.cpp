#include"Solutions.h"
// slower ptr moves one step, fastr pionter move two steps

ListNode * p109::findMiddle(ListNode *h) {
	if (h == NULL) return NULL;
	ListNode * fast = h;
	ListNode * prev{ nullptr };
	ListNode * slow = h;

	while (fast!= NULL && fast->next != NULL) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	// need to break the link!!
	if (prev != NULL) {
		prev->next = NULL; // just move fast pointr
		// break before mid as mid need to be at the root
	}
	
	return slow;
}

TreeNode* p109::sortedListToBST(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *mid = findMiddle(head);
	TreeNode * root = new TreeNode{ mid->val };
	if (mid == head) {
		// just ONE elemnt
		return root;
	}
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(mid->next);
	return root;
}

void p109::test() {
	vector<int> input = { -10, -3, 0, 5, 9 };
	LinkedNodes *lk = new LinkedNodes{ input };
	Tree * r = new Tree{ sortedListToBST(lk->GetHead()) };
	r->BFT();
}