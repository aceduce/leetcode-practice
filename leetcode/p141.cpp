#include"Solutions.h"
// hashset method
bool p141::hasCycle_hashset(ListNode *head) {
	if (!head) return false;
	unordered_set<ListNode *> set;
	while (head) {
		if (set.count(head) != 0) {
			return true;
		}
		else {
			set.insert(head);
			head = head->next;
		}		
	}
	return false;
}


bool p141::hasCycle(ListNode *head) {
	ListNode * fast = head, *slow = head;
	if (fast == NULL || fast->next == NULL) return false;
	fast = fast->next;
	while (fast!= slow) {
		//while (fast != NULL && fast->next != NULL) { change the exit condition
		if (fast == NULL || fast->next == NULL) return false;
			fast = fast->next->next;
			slow = slow->next;
	}
	return true; // successfully out of the while loop
}

void p141::test() {
	
}