#include"Solutions.h"

ListNode* p83::deleteDuplicates(ListNode* head){
	if (head == NULL) return NULL;
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = head;
	ListNode * current = head;
	ListNode * tmp = current->next;
	while (tmp != NULL) { // not the last
		while (tmp != NULL && tmp->val == current->val) {
			tmp = tmp->next;
		}
		current->next = tmp;
		current = tmp;
		if (tmp == NULL) break;
		tmp = current->next;
	}
	return dummy->next;
}


void p83::test() {
	vector<int> v{ 1, 1, 2, 3, 3 };
	LinkedNodes * lk = new LinkedNodes(v);
	lk->PrintListNode();
	ListNode * ans = deleteDuplicates(lk->GetHead());
	LinkedNodes * lk2 = new LinkedNodes(ans);
	lk2->PrintListNode();
	delete lk, lk2;
}