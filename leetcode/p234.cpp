#include"Solutions.h"

// reverse LinkedList is basic skill


void p234::reverse(ListNode * &h) {
	if (!h) return;
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = h;
	ListNode * tail = dummy->next;
	ListNode * cur = dummy->next->next;
	while (cur!= NULL) {
		ListNode * tmp = cur->next;
		cur->next = dummy->next;//tail;
		tail->next = tmp;
		dummy->next = cur;
		cur = tmp;
	}
	h = dummy->next;
}



bool p234::isPalindrome(ListNode* head) {
	if (!head) return true;
	ListNode * slow, *fast;
	slow = fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	// reverse funciton, which is the key here:
	reverse(slow); // slow means the tail in the pointer manipulations
	fast = head;
	// traverse through
	while (slow != NULL) {
		if (slow->val != head->val) return false;
		else {
			slow = slow->next;
			head = head->next;
		}
	}
	return true;
}

void p234::test() {
	ListNode * p = new ListNode{ 1 };
	p->next = new ListNode{ 2 };
	p->next->next = new ListNode{ 3 };
	p->next->next->next = new ListNode{ 2 };
	p->next->next->next->next = new ListNode{ 1 };
	cout << isPalindrome(p) << endl;
}