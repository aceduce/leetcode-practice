#include"Solutions.h"
ListNode* p203::removeElements(ListNode* head, int val) {
	ListNode * dummy = new ListNode{ 0 }, *pre = new ListNode{ 0 };
	dummy->next = head;
	pre->next = head;
	while (head) {
		if (head->val == val) {
			// delete node
			if (head == dummy->next) { // delete head node
				dummy->next = head->next;
				head = dummy->next;
				pre->next = head;
			}
			else {
				pre->next = head->next;
				head = head->next;
				// pre keeps the same, not moving
			}
		}
		else {
			head = head->next;
			pre = pre->next;
		}
	}
	return dummy->next;
}

void p203::test() {
	ListNode h{ 6 };
	h.next = new ListNode{ 2 };
	h.next->next = new ListNode{ 6 };
	h.next->next->next = new ListNode{ 3 };
	h.next->next->next->next = new ListNode{ 4 };
	h.next->next->next->next->next = new ListNode{ 5 };
	h.next->next->next->next->next->next = new ListNode{ 6 };
	ListNode * ans = removeElements(&h, 6);
}

