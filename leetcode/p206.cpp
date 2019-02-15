#include"Solutions.h"
// initializer is differnt fro ListNode * dummmy{0} --> null pointerr
ListNode* p206::reverseList(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode * dummy = new ListNode{ 0 };
	dummy->next = head;
	ListNode * tail = dummy->next;
	ListNode * cur = dummy->next->next;
	while (cur != NULL) {
		ListNode * tmp = cur->next;
		cur->next = dummy->next;
		dummy->next = cur;
		tail->next = tmp;
		cur = tmp;
	}
	return dummy->next;
}

void p206::test() {
	vector<int> input{ 1,2,3,4,5 };
	LinkedNodes ln{ input };
	ln.SetHead(reverseList(ln.GetHead()));
	ln.PrintListNode();
}