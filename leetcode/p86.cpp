#include"Solutions.h"
// only moves the smaller ones, bigger or equals not moved!!
// KEY is to find the boundary
ListNode* p86::partition(ListNode* head, int x) {
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = head;
	ListNode * left = dummy;
	ListNode * pre = dummy;
	ListNode * cur = pre->next;
	while (cur != NULL) {
		// first timer: use a pre-left relation:

		if (pre == left) {
			if (cur->val < x) { // FIND THE LEFT/RIGHT boundary
				left = left->next;
			}
			cur = cur->next;
			pre = pre->next;
		}
		else { // left is fixed already!!
			// small again, but just change the poiners
			if (cur->val < x) { 
				pre->next = cur->next;
				cur->next = left->next;
				left->next = cur;
				// for next cycle
				cur = pre->next;
				left = left->next;
			}
			else {
				cur = cur->next;
				pre = pre->next;
			}
		}
	}
	return dummy->next;
}

void p86::test() {
	vector<int> v{ 1,4,3,2,5,2 };
	LinkedNodes ln{ v };
	ln.PrintListNode();
	ListNode * ans = partition(ln.GetHead(), 3);
	ln.SetHead(ans);
	ln.PrintListNode();
}