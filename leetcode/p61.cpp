#include"Solutions.h"
//#include"Helper.h"
// move forward is challenging
// key is to have a slow and fast pointer (keeps the range!!)
// when k is extremly large (> the span)
ListNode* p61::rotateRight(ListNode* head, int k) {
	if (head == NULL || k == 0) return head;
	int len = 0;
	ListNode* fast = head;
	while (fast != NULL) {
		fast = fast->next;
		len++;
	}
	k = k % len; // effective move steps
	ListNode * slow = head;
	fast = head;
	for (int i = 0; i < k; i++) fast = fast->next;
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	// re-build the connections:
	fast->next = head;
	head = slow->next;
	slow->next = NULL;
	return head;
}

void p61::test() {
	LinkedNodes ln { vector<int> {1,2,3,4, 5} };
	ListNode * ans = rotateRight(ln.GetHead(), 2);
	ln.SetHead(ans);
	ln.PrintListNode();
}