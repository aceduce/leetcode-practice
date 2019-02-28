#include"Solutions.h"

ListNode * p143::findMid(ListNode * h) {
	if (h == NULL)  return h;
	ListNode * f = h;
	ListNode * s = h;
	while (f && (f->next)) {
		f = f->next->next;
		s = s->next;
	}
	return s;
}

// there is a mistake...
ListNode * p143::reverse(ListNode * h) {
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = h;
	if (!h) return NULL;
	ListNode * tail = h;
	ListNode * cur = h->next;
	while (cur) {
		ListNode * tmp = cur->next;
		tail->next = tmp;
		cur->next = dummy->next; //tail;
		dummy->next = cur;
		cur = tmp;
	}
	return dummy->next;
}
// basic skill:
void p143::reorderList(ListNode* head) {
	if (!head) return;
	// 3 steps:
	// a find the mid point
	ListNode * mid = findMid(head);
	// b reverse the List 
	ListNode * head2 = mid->next;
	mid->next = NULL; // break the connections
	head2 = reverse(head2); 
	// c reconfigure
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = head;
	while (head != NULL && head2 != NULL) {
		/* below change the structure too much!!!
		ListNode * tmp = head->next;
		ListNode * tmp2 = head2->next;
		head->next = head2;
		head2->next = tmp;
		head2 = tmp2;
		head = tmp;
		*/
		// guidline is to keep l1 as much as possible
		ListNode * tmp = head->next;
		head->next = head2;
		head2 = head2->next;
		head->next->next = tmp;
		head = tmp;
	}
	head = dummy->next;
}

void p143::test() {
	ListNode * h = new ListNode{ 1 };
	h->next = new ListNode{ 2 };
	h->next->next = new ListNode{ 3 };
	h->next->next->next = new ListNode{ 4 };
	h->next->next->next->next = new ListNode{ 5 };
	h->next->next->next->next->next = new ListNode{ 6 };
	h->next->next->next->next->next->next= new ListNode{ 7 };
	reorderList(h);
}