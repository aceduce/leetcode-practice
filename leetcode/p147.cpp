#include"Solutions.h"
// spend a lot of time debugging...
ListNode* p147::insertionSortList(ListNode* head) {
	if (!head) return NULL;
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = head;
	ListNode * pre = dummy;
	ListNode * cur = head->next;
	ListNode * tmp = cur->next;
	ListNode * scan = head;
	ListNode * pre_cur = head;
	while (cur!= NULL) { // all previous nodes
		while (scan != cur && scan->val <= cur->val) {
			scan = scan->next;
			pre = pre->next;
		}
		// need to swap scan and cur now
		if (scan == cur) { // no need to move any node
			cur = cur->next;
			pre_cur = pre_cur->next;
			scan = dummy->next;
			pre = dummy;
			continue;
		}
		else { // need to swap
			pre_cur->next = cur->next;
			pre->next = cur;
			cur->next = scan;
			cur = pre_cur->next;
			//pre_cur = pre_cur->next;
			scan = dummy->next;
			pre = dummy;
			//break;
		}
	}
	return dummy->next;
}

void p147::test() {
	ListNode * h = new ListNode{ 4 };
	h->next = new ListNode{ 2 };
	h->next->next = new ListNode{ 1 };
	h->next->next->next = new ListNode{ 3 };
	//h->next->next->next->next = new ListNode{ 5 };
	//h->next->next->next->next->next = new ListNode{ 6 };
	//h->next->next->next->next->next->next = new ListNode{ 7 };
	ListNode * ans = insertionSortList(h);
	
}