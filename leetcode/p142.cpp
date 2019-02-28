#include"Solutions.h"
// use hashmap
ListNode * p142::detectCycle(ListNode *head) {
	unordered_set<ListNode *> set;
	if (!head) return NULL;
	while (head != NULL) {
		if (set.count(head) != 0)
			return head;
		else {
			set.insert(head);
			head = head->next;
		}
	}
	return NULL;
}

void p142::test() {

}
